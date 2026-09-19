// ScientificCalculator.cpp
// A dark-themed scientific calculator for Windows, built with raw Win32 API.
//
// Compile with MinGW-w64:
//   g++ -O2 -mwindows ScientificCalculator.cpp -o ScientificCalculator.exe
//
// Compile with MSVC (Developer Command Prompt):
//   cl /EHsc /O2 ScientificCalculator.cpp /link /SUBSYSTEM:WINDOWS
//
// Or create a new "Windows Desktop Application" project in Visual Studio
// and drop this file in as main.cpp.

// code by Anthropic Inc. Claude AI LLM Sonnet 5 Extra 

#define _USE_MATH_DEFINES
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <cmath>
#include <cwchar>
#include <cstdlib>
#include <string>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

// ---------------------------------------------------------------------
// Control IDs
// ---------------------------------------------------------------------
enum {
    ID_DISPLAY = 100,
    ID_STATUS,
    ID_0, ID_1, ID_2, ID_3, ID_4, ID_5, ID_6, ID_7, ID_8, ID_9,
    ID_DOT,
    ID_ADD, ID_SUB, ID_MUL, ID_DIV, ID_POW, ID_MOD,
    ID_EQUALS,
    ID_CLEAR, ID_CLEAR_ENTRY, ID_BACKSPACE,
    ID_SIGN, ID_PERCENT,
    ID_SQRT, ID_SQUARE, ID_RECIP, ID_FACT,
    ID_SIN, ID_COS, ID_TAN,
    ID_LOG, ID_LN,
    ID_PI, ID_E,
    ID_SECOND, ID_DEGRAD,
    ID_MC, ID_MR, ID_MS, ID_MPLUS, ID_MMINUS
};

enum ButtonCategory { CAT_DIGIT, CAT_OP, CAT_EQUALS, CAT_FUNC, CAT_CLEAR, CAT_MEM, CAT_TOGGLE };

// ---------------------------------------------------------------------
// Layout constants (everything below is derived from these)
// ---------------------------------------------------------------------
constexpr int MARGIN     = 10;
constexpr int STATUS_H   = 22;
constexpr int DISPLAY_H  = 90;
constexpr int ROW_H      = 55;
constexpr int CLIENT_W   = 480;
constexpr int TOTAL_H    = MARGIN + STATUS_H + DISPLAY_H + MARGIN +
                            (4 * ROW_H) + MARGIN + (4 * ROW_H) + MARGIN +
                            ROW_H + MARGIN;

// ---------------------------------------------------------------------
// Globals
// ---------------------------------------------------------------------
HWND hDisplay, hStatus;
HWND hBtnSin, hBtnCos, hBtnTan, hBtnLog, hBtnLn, hBtn2nd, hBtnDegRad;
HFONT hFontDisplay, hFontStatus, hFontButton, hFontButtonBold;
HBRUSH hBrushDisplay, g_hBrushWindowBG;

bool isDegreeMode = true;
bool secondMode   = false;

struct CalcState {
    double accumulator   = 0.0;
    char   pendingOp     = 0;      // '+','-','*','/','^','m'(mod), 0 = none
    bool   startNewNumber = true;
    bool   hasDecimal    = false;
    std::wstring displayText = L"0";
    double memory         = 0.0;
};
CalcState calc;

// ---------------------------------------------------------------------
// Number formatting / parsing
// ---------------------------------------------------------------------
std::wstring FormatNumber(double val) {
    if (std::isnan(val) || std::isinf(val)) return L"Error";
    wchar_t buf[64];
    swprintf(buf, 64, L"%.10g", val);
    return std::wstring(buf);
}

double CurrentValue() {
    return wcstod(calc.displayText.c_str(), nullptr);
}

void UpdateDisplay() {
    SetWindowTextW(hDisplay, calc.displayText.c_str());
}

void UpdateStatus() {
    std::wstring s = isDegreeMode ? L"DEG" : L"RAD";
    if (calc.memory != 0.0) s += L"   M";
    SetWindowTextW(hStatus, s.c_str());
}

// ---------------------------------------------------------------------
// Entry
// ---------------------------------------------------------------------
void InputDigit(int d) {
    if (calc.displayText == L"Error") calc.displayText = L"0";
    if (calc.startNewNumber) {
        calc.displayText = std::to_wstring(d);
        calc.startNewNumber = false;
        calc.hasDecimal = false;
    } else {
        if (calc.displayText == L"0") calc.displayText.clear();
        if (calc.displayText.size() < 15) calc.displayText += std::to_wstring(d);
    }
    UpdateDisplay();
}

void InputDecimal() {
    if (calc.displayText == L"Error") calc.displayText = L"0";
    if (calc.startNewNumber) {
        calc.displayText = L"0.";
        calc.startNewNumber = false;
        calc.hasDecimal = true;
    } else if (!calc.hasDecimal) {
        calc.displayText += L".";
        calc.hasDecimal = true;
    }
    UpdateDisplay();
}

void InputConstant(double val) {
    calc.displayText = FormatNumber(val);
    calc.startNewNumber = true;
    UpdateDisplay();
}

// ---------------------------------------------------------------------
// Core arithmetic (accumulator + pending operator, chains like a
// classic calculator: 5 + 3 + 2 = shows 8 then 10)
// ---------------------------------------------------------------------
void ApplyPendingOp() {
    double operand = CurrentValue();
    if (calc.pendingOp == 0) {
        calc.accumulator = operand;
        return;
    }
    double result = 0.0;
    bool ok = true;
    switch (calc.pendingOp) {
        case '+': result = calc.accumulator + operand; break;
        case '-': result = calc.accumulator - operand; break;
        case '*': result = calc.accumulator * operand; break;
        case '/':
            if (operand == 0.0) ok = false;
            else result = calc.accumulator / operand;
            break;
        case '^': result = std::pow(calc.accumulator, operand); break;
        case 'm':
            if (operand == 0.0) ok = false;
            else result = std::fmod(calc.accumulator, operand);
            break;
    }
    if (!ok || std::isnan(result) || std::isinf(result)) {
        calc.displayText = L"Error";
        calc.accumulator = 0.0;
    } else {
        calc.accumulator = result;
        calc.displayText = FormatNumber(result);
    }
}

void SetOperator(char op) {
    if (!calc.startNewNumber || calc.pendingOp == 0) ApplyPendingOp();
    calc.pendingOp = op;
    calc.startNewNumber = true;
    UpdateDisplay();
}

void OnEquals() {
    ApplyPendingOp();
    calc.pendingOp = 0;
    calc.startNewNumber = true;
    UpdateDisplay();
}

void OnPercent() {
    double val = CurrentValue();
    double result = (calc.pendingOp != 0) ? (calc.accumulator * val / 100.0) : (val / 100.0);
    calc.displayText = FormatNumber(result);
    calc.startNewNumber = true;
    UpdateDisplay();
}

void OnToggleSign() {
    calc.displayText = FormatNumber(-CurrentValue());
    UpdateDisplay();
}

void OnClear() {
    calc = CalcState();
    UpdateStatus();
    UpdateDisplay();
}

void OnClearEntry() {
    calc.displayText = L"0";
    calc.startNewNumber = true;
    calc.hasDecimal = false;
    UpdateDisplay();
}

void OnBackspace() {
    if (calc.displayText == L"Error") { OnClearEntry(); return; }
    if (calc.startNewNumber) return;
    if (calc.displayText.size() <= 1 ||
        (calc.displayText.size() == 2 && calc.displayText[0] == L'-')) {
        calc.displayText = L"0";
        calc.startNewNumber = true;
        calc.hasDecimal = false;
    } else {
        wchar_t last = calc.displayText.back();
        calc.displayText.pop_back();
        if (last == L'.') calc.hasDecimal = false;
    }
    UpdateDisplay();
}

// ---------------------------------------------------------------------
// Scientific functions
// ---------------------------------------------------------------------
void ApplyUnaryMath(int which) { // 0=sqrt 1=square 2=1/x 3=factorial
    double v = CurrentValue();
    double r = 0.0;
    bool ok = true;
    switch (which) {
        case 0: if (v < 0) ok = false; else r = std::sqrt(v); break;
        case 1: r = v * v; break;
        case 2: if (v == 0) ok = false; else r = 1.0 / v; break;
        case 3:
            if (v < 0 || v != std::floor(v) || v > 170) ok = false;
            else r = std::tgamma(v + 1.0);
            break;
    }
    calc.displayText = (!ok || std::isnan(r) || std::isinf(r)) ? L"Error" : FormatNumber(r);
    calc.startNewNumber = true;
    UpdateDisplay();
}

void OnTrig(int which) { // 0=sin 1=cos 2=tan (or inverse, if secondMode)
    double v = CurrentValue();
    double result = 0.0;
    bool ok = true;
    if (!secondMode) {
        double rad = isDegreeMode ? (v * M_PI / 180.0) : v;
        switch (which) {
            case 0: result = std::sin(rad); break;
            case 1: result = std::cos(rad); break;
            case 2: result = std::tan(rad); break;
        }
    } else {
        switch (which) {
            case 0: if (v < -1 || v > 1) ok = false; else result = std::asin(v); break;
            case 1: if (v < -1 || v > 1) ok = false; else result = std::acos(v); break;
            case 2: result = std::atan(v); break;
        }
        if (ok && isDegreeMode) result = result * 180.0 / M_PI;
    }
    calc.displayText = (!ok || std::isnan(result) || std::isinf(result)) ? L"Error" : FormatNumber(result);
    calc.startNewNumber = true;
    UpdateDisplay();
}

void OnLogLn(int which) { // 0=log/10^x  1=ln/e^x (2nd toggles pair)
    double v = CurrentValue();
    double result = 0.0;
    bool ok = true;
    if (!secondMode) {
        if (v <= 0) ok = false;
        else result = (which == 0) ? std::log10(v) : std::log(v);
    } else {
        result = (which == 0) ? std::pow(10.0, v) : std::exp(v);
    }
    calc.displayText = (!ok || std::isnan(result) || std::isinf(result)) ? L"Error" : FormatNumber(result);
    calc.startNewNumber = true;
    UpdateDisplay();
}

void ToggleSecondMode() {
    secondMode = !secondMode;
    SetWindowTextW(hBtnSin, secondMode ? L"asin" : L"sin");
    SetWindowTextW(hBtnCos, secondMode ? L"acos" : L"cos");
    SetWindowTextW(hBtnTan, secondMode ? L"atan" : L"tan");
    SetWindowTextW(hBtnLog, secondMode ? L"10^x" : L"log");
    SetWindowTextW(hBtnLn,  secondMode ? L"e^x"  : L"ln");
    InvalidateRect(hBtn2nd, nullptr, TRUE);
}

void ToggleDegRad() {
    isDegreeMode = !isDegreeMode;
    SetWindowTextW(hBtnDegRad, isDegreeMode ? L"DEG" : L"RAD");
    UpdateStatus();
}

// ---------------------------------------------------------------------
// Memory
// ---------------------------------------------------------------------
void OnMC()     { calc.memory = 0.0; UpdateStatus(); }
void OnMR()     { calc.displayText = FormatNumber(calc.memory); calc.startNewNumber = true; UpdateDisplay(); }
void OnMS()     { calc.memory = CurrentValue(); UpdateStatus(); calc.startNewNumber = true; }
void OnMPlus()  { calc.memory += CurrentValue(); UpdateStatus(); calc.startNewNumber = true; }
void OnMMinus() { calc.memory -= CurrentValue(); UpdateStatus(); calc.startNewNumber = true; }

// ---------------------------------------------------------------------
// Dark theme drawing
// ---------------------------------------------------------------------
COLORREF DarkenColor(COLORREF c, double factor) {
    int r = (int)(GetRValue(c) * factor);
    int g = (int)(GetGValue(c) * factor);
    int b = (int)(GetBValue(c) * factor);
    return RGB(r, g, b);
}

void GetCategoryColors(int cat, bool active, COLORREF &bg, COLORREF &fg) {
    switch (cat) {
        case CAT_DIGIT:  bg = RGB(45, 45, 50);  fg = RGB(240, 240, 240); break;
        case CAT_OP:     bg = RGB(58, 58, 66);  fg = RGB(140, 148, 255); break;
        case CAT_EQUALS: bg = RGB(102, 126, 234); fg = RGB(255, 255, 255); break;
        case CAT_FUNC:   bg = RGB(38, 38, 43);  fg = RGB(179, 175, 255); break;
        case CAT_CLEAR:  bg = RGB(58, 31, 31);  fg = RGB(255, 107, 107); break;
        case CAT_MEM:    bg = RGB(31, 42, 58);  fg = RGB(110, 193, 255); break;
        case CAT_TOGGLE:
            if (active) { bg = RGB(102, 126, 234); fg = RGB(255, 255, 255); }
            else        { bg = RGB(38, 38, 43);    fg = RGB(179, 175, 255); }
            break;
        default: bg = RGB(45, 45, 50); fg = RGB(240, 240, 240); break;
    }
}

HWND CreateCalcButton(HWND parent, HINSTANCE hInst, const wchar_t* text, int id,
                       int x, int y, int w, int h, int category) {
    HWND btn = CreateWindowW(L"BUTTON", text, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
                              x, y, w, h, parent, (HMENU)(INT_PTR)id, hInst, nullptr);
    SetWindowLongPtr(btn, GWLP_USERDATA, (LONG_PTR)category);
    return btn;
}

void DrawCalcButton(LPDRAWITEMSTRUCT dis) {
    int category = (int)GetWindowLongPtr(dis->hwndItem, GWLP_USERDATA);
    int id = GetDlgCtrlID(dis->hwndItem);
    bool active = (id == ID_SECOND) && secondMode;

    COLORREF bg, fg;
    GetCategoryColors(category, active, bg, fg);

    if (dis->itemState & ODS_SELECTED) bg = DarkenColor(bg, 0.7);

    HDC hdc = dis->hDC;
    RECT rc = dis->rcItem;

    HBRUSH brush = CreateSolidBrush(bg);
    HPEN pen = CreatePen(PS_SOLID, 1, bg);
    HGDIOBJ oldBrush = SelectObject(hdc, brush);
    HGDIOBJ oldPen = SelectObject(hdc, pen);

    RoundRect(hdc, rc.left + 2, rc.top + 2, rc.right - 2, rc.bottom - 2, 12, 12);

    SelectObject(hdc, oldBrush);
    SelectObject(hdc, oldPen);
    DeleteObject(brush);
    DeleteObject(pen);

    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, fg);
    HGDIOBJ oldFont = SelectObject(hdc, (category == CAT_EQUALS) ? hFontButtonBold : hFontButton);

    wchar_t text[32];
    GetWindowTextW(dis->hwndItem, text, 32);
    DrawTextW(hdc, text, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    SelectObject(hdc, oldFont);
}

// ---------------------------------------------------------------------
// Window procedure
// ---------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            HINSTANCE hInst = ((LPCREATESTRUCT)lParam)->hInstance;

            hFontDisplay = CreateFontW(46, 0, 0, 0, FW_LIGHT, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Segoe UI");
            hFontStatus = CreateFontW(16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Segoe UI");
            hFontButton = CreateFontW(19, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Segoe UI");
            hFontButtonBold = CreateFontW(22, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Segoe UI");

            hBrushDisplay = CreateSolidBrush(RGB(12, 12, 14));

            hStatus = CreateWindowW(L"STATIC", L"DEG", WS_CHILD | WS_VISIBLE | SS_LEFT,
                MARGIN, MARGIN, CLIENT_W - 2 * MARGIN, STATUS_H, hwnd,
                (HMENU)(INT_PTR)ID_STATUS, hInst, nullptr);
            SendMessageW(hStatus, WM_SETFONT, (WPARAM)hFontStatus, (LPARAM)TRUE);

            int yDisplay = MARGIN + STATUS_H;
            hDisplay = CreateWindowW(L"EDIT", L"0",
                WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_READONLY | WS_BORDER,
                MARGIN, yDisplay, CLIENT_W - 2 * MARGIN, DISPLAY_H, hwnd,
                (HMENU)(INT_PTR)ID_DISPLAY, hInst, nullptr);
            SendMessageW(hDisplay, WM_SETFONT, (WPARAM)hFontDisplay, (LPARAM)TRUE);

            int usableW = CLIENT_W - 2 * MARGIN;
            int sciColW = usableW / 6;
            int numColW = usableW / 4;
            int btnH = ROW_H - 6;

            int ySci = yDisplay + DISPLAY_H + MARGIN;
            int y0 = ySci, y1 = ySci + ROW_H, y2 = ySci + 2 * ROW_H, y3 = ySci + 3 * ROW_H;
            auto SX = [&](int c) { return MARGIN + c * sciColW; };

            // Row 0: memory + backspace
            CreateCalcButton(hwnd, hInst, L"MC", ID_MC, SX(0), y0, sciColW - 4, btnH, CAT_MEM);
            CreateCalcButton(hwnd, hInst, L"MR", ID_MR, SX(1), y0, sciColW - 4, btnH, CAT_MEM);
            CreateCalcButton(hwnd, hInst, L"MS", ID_MS, SX(2), y0, sciColW - 4, btnH, CAT_MEM);
            CreateCalcButton(hwnd, hInst, L"M+", ID_MPLUS, SX(3), y0, sciColW - 4, btnH, CAT_MEM);
            CreateCalcButton(hwnd, hInst, L"M-", ID_MMINUS, SX(4), y0, sciColW - 4, btnH, CAT_MEM);
            CreateCalcButton(hwnd, hInst, L"<-", ID_BACKSPACE, SX(5), y0, sciColW - 4, btnH, CAT_CLEAR);

            // Row 1: mod, 2nd, deg/rad, %, sqrt, n!
            CreateCalcButton(hwnd, hInst, L"mod", ID_MOD, SX(0), y1, sciColW - 4, btnH, CAT_OP);
            hBtn2nd = CreateCalcButton(hwnd, hInst, L"2nd", ID_SECOND, SX(1), y1, sciColW - 4, btnH, CAT_TOGGLE);
            hBtnDegRad = CreateCalcButton(hwnd, hInst, L"DEG", ID_DEGRAD, SX(2), y1, sciColW - 4, btnH, CAT_FUNC);
            CreateCalcButton(hwnd, hInst, L"%", ID_PERCENT, SX(3), y1, sciColW - 4, btnH, CAT_FUNC);
            CreateCalcButton(hwnd, hInst, L"sqrt", ID_SQRT, SX(4), y1, sciColW - 4, btnH, CAT_FUNC);
            CreateCalcButton(hwnd, hInst, L"n!", ID_FACT, SX(5), y1, sciColW - 4, btnH, CAT_FUNC);

            // Row 2: sin, cos, tan, x^2, x^y, 1/x
            hBtnSin = CreateCalcButton(hwnd, hInst, L"sin", ID_SIN, SX(0), y2, sciColW - 4, btnH, CAT_FUNC);
            hBtnCos = CreateCalcButton(hwnd, hInst, L"cos", ID_COS, SX(1), y2, sciColW - 4, btnH, CAT_FUNC);
            hBtnTan = CreateCalcButton(hwnd, hInst, L"tan", ID_TAN, SX(2), y2, sciColW - 4, btnH, CAT_FUNC);
            CreateCalcButton(hwnd, hInst, L"x^2", ID_SQUARE, SX(3), y2, sciColW - 4, btnH, CAT_FUNC);
            CreateCalcButton(hwnd, hInst, L"x^y", ID_POW, SX(4), y2, sciColW - 4, btnH, CAT_OP);
            CreateCalcButton(hwnd, hInst, L"1/x", ID_RECIP, SX(5), y2, sciColW - 4, btnH, CAT_FUNC);

            // Row 3: log, ln, pi, e, C, CE
            hBtnLog = CreateCalcButton(hwnd, hInst, L"log", ID_LOG, SX(0), y3, sciColW - 4, btnH, CAT_FUNC);
            hBtnLn = CreateCalcButton(hwnd, hInst, L"ln", ID_LN, SX(1), y3, sciColW - 4, btnH, CAT_FUNC);
            CreateCalcButton(hwnd, hInst, L"pi", ID_PI, SX(2), y3, sciColW - 4, btnH, CAT_FUNC);
            CreateCalcButton(hwnd, hInst, L"e", ID_E, SX(3), y3, sciColW - 4, btnH, CAT_FUNC);
            CreateCalcButton(hwnd, hInst, L"C", ID_CLEAR, SX(4), y3, sciColW - 4, btnH, CAT_CLEAR);
            CreateCalcButton(hwnd, hInst, L"CE", ID_CLEAR_ENTRY, SX(5), y3, sciColW - 4, btnH, CAT_CLEAR);

            // Numpad section
            int yNum = ySci + 4 * ROW_H + MARGIN;
            int y4 = yNum, y5 = yNum + ROW_H, y6 = yNum + 2 * ROW_H, y7 = yNum + 3 * ROW_H;
            auto NX = [&](int c) { return MARGIN + c * numColW; };

            CreateCalcButton(hwnd, hInst, L"7", ID_7, NX(0), y4, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L"8", ID_8, NX(1), y4, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L"9", ID_9, NX(2), y4, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L"/", ID_DIV, NX(3), y4, numColW - 4, btnH, CAT_OP);

            CreateCalcButton(hwnd, hInst, L"4", ID_4, NX(0), y5, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L"5", ID_5, NX(1), y5, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L"6", ID_6, NX(2), y5, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L"*", ID_MUL, NX(3), y5, numColW - 4, btnH, CAT_OP);

            CreateCalcButton(hwnd, hInst, L"1", ID_1, NX(0), y6, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L"2", ID_2, NX(1), y6, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L"3", ID_3, NX(2), y6, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L"-", ID_SUB, NX(3), y6, numColW - 4, btnH, CAT_OP);

            CreateCalcButton(hwnd, hInst, L"0", ID_0, NX(0), y7, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L".", ID_DOT, NX(1), y7, numColW - 4, btnH, CAT_DIGIT);
            CreateCalcButton(hwnd, hInst, L"+/-", ID_SIGN, NX(2), y7, numColW - 4, btnH, CAT_FUNC);
            CreateCalcButton(hwnd, hInst, L"+", ID_ADD, NX(3), y7, numColW - 4, btnH, CAT_OP);

            int yEq = yNum + 4 * ROW_H + MARGIN;
            CreateCalcButton(hwnd, hInst, L"=", ID_EQUALS, MARGIN, yEq, usableW - 4, ROW_H - 6, CAT_EQUALS);

            UpdateStatus();
            return 0;
        }

        case WM_COMMAND: {
            int id = LOWORD(wParam);
            if (id >= ID_0 && id <= ID_9) { InputDigit(id - ID_0); break; }
            switch (id) {
                case ID_DOT:          InputDecimal(); break;
                case ID_ADD:          SetOperator('+'); break;
                case ID_SUB:          SetOperator('-'); break;
                case ID_MUL:          SetOperator('*'); break;
                case ID_DIV:          SetOperator('/'); break;
                case ID_POW:          SetOperator('^'); break;
                case ID_MOD:          SetOperator('m'); break;
                case ID_EQUALS:       OnEquals(); break;
                case ID_CLEAR:        OnClear(); break;
                case ID_CLEAR_ENTRY:  OnClearEntry(); break;
                case ID_BACKSPACE:    OnBackspace(); break;
                case ID_SIGN:         OnToggleSign(); break;
                case ID_PERCENT:      OnPercent(); break;
                case ID_SQRT:         ApplyUnaryMath(0); break;
                case ID_SQUARE:       ApplyUnaryMath(1); break;
                case ID_RECIP:        ApplyUnaryMath(2); break;
                case ID_FACT:         ApplyUnaryMath(3); break;
                case ID_SIN:          OnTrig(0); break;
                case ID_COS:          OnTrig(1); break;
                case ID_TAN:          OnTrig(2); break;
                case ID_LOG:          OnLogLn(0); break;
                case ID_LN:           OnLogLn(1); break;
                case ID_PI:           InputConstant(M_PI); break;
                case ID_E:            InputConstant(M_E); break;
                case ID_SECOND:       ToggleSecondMode(); break;
                case ID_DEGRAD:       ToggleDegRad(); break;
                case ID_MC:           OnMC(); break;
                case ID_MR:           OnMR(); break;
                case ID_MS:           OnMS(); break;
                case ID_MPLUS:        OnMPlus(); break;
                case ID_MMINUS:       OnMMinus(); break;
            }
            break;
        }

        case WM_DRAWITEM: {
            LPDRAWITEMSTRUCT dis = (LPDRAWITEMSTRUCT)lParam;
            if (dis->CtlType == ODT_BUTTON) { DrawCalcButton(dis); return TRUE; }
            return FALSE;
        }

        case WM_CTLCOLOREDIT: {
            HDC hdcEdit = (HDC)wParam;
            SetTextColor(hdcEdit, RGB(255, 255, 255));
            SetBkColor(hdcEdit, RGB(12, 12, 14));
            return (LRESULT)hBrushDisplay;
        }

        case WM_CTLCOLORSTATIC: {
            HDC hdcStatic = (HDC)wParam;
            SetTextColor(hdcStatic, RGB(140, 148, 255));
            SetBkMode(hdcStatic, TRANSPARENT);
            return (LRESULT)g_hBrushWindowBG;
        }

        case WM_DESTROY:
            DeleteObject(hFontDisplay);
            DeleteObject(hFontStatus);
            DeleteObject(hFontButton);
            DeleteObject(hFontButtonBold);
            DeleteObject(hBrushDisplay);
            DeleteObject(g_hBrushWindowBG);
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

// ---------------------------------------------------------------------
// Entry point
// ---------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    (void)hPrevInstance; (void)lpCmdLine;

    const wchar_t CLASS_NAME[] = L"DarkSciCalcWindowClass";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    g_hBrushWindowBG = CreateSolidBrush(RGB(24, 24, 27));
    wc.hbrBackground = g_hBrushWindowBG;
    RegisterClassW(&wc);

    RECT wr = { 0, 0, CLIENT_W, TOTAL_H };
    DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
    AdjustWindowRect(&wr, style, FALSE);

    HWND hwndMain = CreateWindowExW(0, CLASS_NAME, L"Scientific Calculator", style,
        CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top,
        nullptr, nullptr, hInstance, nullptr);
    if (!hwndMain) return 0;

    ShowWindow(hwndMain, nCmdShow);
    UpdateWindow(hwndMain);

    ACCEL accels[] = {
        { FVIRTKEY, '0', ID_0 }, { FVIRTKEY, '1', ID_1 }, { FVIRTKEY, '2', ID_2 },
        { FVIRTKEY, '3', ID_3 }, { FVIRTKEY, '4', ID_4 }, { FVIRTKEY, '5', ID_5 },
        { FVIRTKEY, '6', ID_6 }, { FVIRTKEY, '7', ID_7 }, { FVIRTKEY, '8', ID_8 },
        { FVIRTKEY, '9', ID_9 },
        { FVIRTKEY, VK_ADD,      ID_ADD },
        { FVIRTKEY, VK_SUBTRACT, ID_SUB },
        { FVIRTKEY, VK_MULTIPLY, ID_MUL },
        { FVIRTKEY, VK_DIVIDE,   ID_DIV },
        { FVIRTKEY, VK_RETURN,   ID_EQUALS },
        { FVIRTKEY, VK_ESCAPE,   ID_CLEAR },
        { FVIRTKEY, VK_BACK,     ID_BACKSPACE },
        { FVIRTKEY, VK_DECIMAL,  ID_DOT },
        { FVIRTKEY, VK_DELETE,   ID_CLEAR_ENTRY },
    };
    HACCEL hAccel = CreateAcceleratorTable(accels, sizeof(accels) / sizeof(ACCEL));

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (!TranslateAccelerator(hwndMain, hAccel, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}
