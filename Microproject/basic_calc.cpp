#include <windows.h>
#include <string>
#include <sstream>

// basic calculator using windows GUI API
//code by OpenAi ChatGPT v4

#define BTN_0 100
#define BTN_1 101
#define BTN_2 102
#define BTN_3 103
#define BTN_4 104
#define BTN_5 105
#define BTN_6 106
#define BTN_7 107
#define BTN_8 108
#define BTN_9 109

#define BTN_ADD 110
#define BTN_SUB 111
#define BTN_MUL 112
#define BTN_DIV 113
#define BTN_EQUAL 114
#define BTN_CLEAR 115
#define BTN_DOT 116

HWND display;

double firstNumber = 0;
char operation = 0;
bool newNumber = true;


// Put text in display
void SetDisplay(std::string text)
{
    SetWindowTextA(display, text.c_str());
}


// Add a digit
void AddNumber(char digit)
{
    char text[100];
    GetWindowTextA(display, text, 100);

    std::string number = text;

    if (newNumber || number == "0")
    {
        number = digit;
        newNumber = false;
    }
    else
    {
        number += digit;
    }

    SetDisplay(number);
}


// Perform calculation
void Calculate()
{
    char text[100];
    GetWindowTextA(display, text, 100);

    double secondNumber = atof(text);
    double result = 0;

    switch (operation)
    {
        case '+':
            result = firstNumber + secondNumber;
            break;

        case '-':
            result = firstNumber - secondNumber;
            break;

        case '*':
            result = firstNumber * secondNumber;
            break;

        case '/':
            if (secondNumber == 0)
            {
                SetDisplay("Error");
                newNumber = true;
                return;
            }

            result = firstNumber / secondNumber;
            break;
    }

    std::ostringstream out;
    out << result;

    SetDisplay(out.str());

    newNumber = true;
}


// Window procedure
LRESULT CALLBACK WindowProcedure(
    HWND window,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (message)
    {
        case WM_CREATE:
        {
            // Display
            display = CreateWindowA(
                "EDIT",
                "0",
                WS_CHILD |
                WS_VISIBLE |
                ES_RIGHT |
                ES_READONLY,

                20, 20,
                300, 50,

                window,
                NULL,
                NULL,
                NULL
            );


            // Buttons
            int x = 20;
            int y = 90;

            int width = 70;
            int height = 50;
            int gap = 5;


            // 7 8 9 /
            CreateWindowA("BUTTON", "7",
                WS_VISIBLE | WS_CHILD,
                x, y, width, height,
                window, (HMENU)BTN_7, NULL, NULL);

            CreateWindowA("BUTTON", "8",
                WS_VISIBLE | WS_CHILD,
                x + 75, y, width, height,
                window, (HMENU)BTN_8, NULL, NULL);

            CreateWindowA("BUTTON", "9",
                WS_VISIBLE | WS_CHILD,
                x + 150, y, width, height,
                window, (HMENU)BTN_9, NULL, NULL);

            CreateWindowA("BUTTON", "/",
                WS_VISIBLE | WS_CHILD,
                x + 225, y, width, height,
                window, (HMENU)BTN_DIV, NULL, NULL);


            // 4 5 6 *
            y += 55;

            CreateWindowA("BUTTON", "4",
                WS_VISIBLE | WS_CHILD,
                x, y, width, height,
                window, (HMENU)BTN_4, NULL, NULL);

            CreateWindowA("BUTTON", "5",
                WS_VISIBLE | WS_CHILD,
                x + 75, y, width, height,
                window, (HMENU)BTN_5, NULL, NULL);

            CreateWindowA("BUTTON", "6",
                WS_VISIBLE | WS_CHILD,
                x + 150, y, width, height,
                window, (HMENU)BTN_6, NULL, NULL);

            CreateWindowA("BUTTON", "*",
                WS_VISIBLE | WS_CHILD,
                x + 225, y, width, height,
                window, (HMENU)BTN_MUL, NULL, NULL);


            // 1 2 3 -
            y += 55;

            CreateWindowA("BUTTON", "1",
                WS_VISIBLE | WS_CHILD,
                x, y, width, height,
                window, (HMENU)BTN_1, NULL, NULL);

            CreateWindowA("BUTTON", "2",
                WS_VISIBLE | WS_CHILD,
                x + 75, y, width, height,
                window, (HMENU)BTN_2, NULL, NULL);

            CreateWindowA("BUTTON", "3",
                WS_VISIBLE | WS_CHILD,
                x + 150, y, width, height,
                window, (HMENU)BTN_3, NULL, NULL);

            CreateWindowA("BUTTON", "-",
                WS_VISIBLE | WS_CHILD,
                x + 225, y, width, height,
                window, (HMENU)BTN_SUB, NULL, NULL);


            // 0 . = +
            y += 55;

            CreateWindowA("BUTTON", "0",
                WS_VISIBLE | WS_CHILD,
                x, y, width, height,
                window, (HMENU)BTN_0, NULL, NULL);

            CreateWindowA("BUTTON", ".",
                WS_VISIBLE | WS_CHILD,
                x + 75, y, width, height,
                window, (HMENU)BTN_DOT, NULL, NULL);

            CreateWindowA("BUTTON", "=",
                WS_VISIBLE | WS_CHILD,
                x + 150, y, width, height,
                window, (HMENU)BTN_EQUAL, NULL, NULL);

            CreateWindowA("BUTTON", "+",
                WS_VISIBLE | WS_CHILD,
                x + 225, y, width, height,
                window, (HMENU)BTN_ADD, NULL, NULL);


            // Clear
            y += 55;

            CreateWindowA("BUTTON", "C",
                WS_VISIBLE | WS_CHILD,
                x, y, width * 4 + gap * 3, height,
                window, (HMENU)BTN_CLEAR, NULL, NULL);

            break;
        }


        case WM_COMMAND:
        {
            int id = LOWORD(wParam);


            // Numbers
            if (id >= BTN_0 && id <= BTN_9)
            {
                char digit = '0' + (id - BTN_0);
                AddNumber(digit);
            }


            // Decimal point
            else if (id == BTN_DOT)
            {
                char text[100];

                GetWindowTextA(
                    display,
                    text,
                    100
                );

                std::string number = text;

                if (number.find('.') == std::string::npos)
                {
                    number += ".";
                    SetDisplay(number);
                    newNumber = false;
                }
            }


            // Operators
            else if (
                id == BTN_ADD ||
                id == BTN_SUB ||
                id == BTN_MUL ||
                id == BTN_DIV)
            {
                char text[100];

                GetWindowTextA(
                    display,
                    text,
                    100
                );

                firstNumber = atof(text);

                if (id == BTN_ADD)
                    operation = '+';

                else if (id == BTN_SUB)
                    operation = '-';

                else if (id == BTN_MUL)
                    operation = '*';

                else
                    operation = '/';

                newNumber = true;
            }


            // Equals
            else if (id == BTN_EQUAL)
            {
                Calculate();
            }


            // Clear
            else if (id == BTN_CLEAR)
            {
                firstNumber = 0;
                operation = 0;
                newNumber = true;

                SetDisplay("0");
            }

            break;
        }


        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProcA(
        window,
        message,
        wParam,
        lParam
    );
}


// Main function
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE,
    LPSTR,
    int nCmdShow)
{
    const char CLASS_NAME[] = "SimpleCalculator";


    WNDCLASSA wc = {};

    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClassA(&wc);


    HWND window = CreateWindowA(
        CLASS_NAME,
        "Calculator",

        WS_OVERLAPPED |
        WS_CAPTION |
        WS_SYSMENU |
        WS_MINIMIZEBOX,

        500, 200,
        350, 400,

        NULL,
        NULL,
        hInstance,
        NULL
    );


    if (!window)
        return 0;


    ShowWindow(window, nCmdShow);


    MSG message = {};

    while (GetMessageA(
        &message,
        NULL,
        0,
        0))
    {
        TranslateMessage(&message);
        DispatchMessageA(&message);
    }


    return 0;
}
