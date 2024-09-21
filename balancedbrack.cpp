#include <windows.h>
#include <string>
#include <sstream>
#include <stack>
#include <iostream>

using namespace std;

bool ArePair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    else if (opening == '{' && closing == '}') return true;
    else if (opening == '[' && closing == ']') return true;
    return false;
}

bool AreParaBalanced(string exp) {
    stack<char> S;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (S.empty() || !ArePair(S.top(), exp[i])) {
                return false;
            } else {
                S.pop();
            }
        }
    }
    return S.empty();
}

string TestBalancedParentheses() {
    string testCases[] = {
        "()", "{}", "[]", "({[]})", "{[()()]}", "(([]{}){})", "", "(", "}", "[{]}", "{[()]", "(}", "({[})", "(()"
    };

    bool expectedResults[] = {
        true, true, true, true, true, true, true, false, false, false, false, false, false, false
    };

    ostringstream result;
    for (int i = 0; i < 14; i++) {
        bool isBalanced = AreParaBalanced(testCases[i]);
        result << "Test case " << i + 1 << ": " << testCases[i] << " -> "
               << (isBalanced == expectedResults[i] ? "Passed" : "Failed") << "\n";
    }
    return result.str();
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hwndText;
    switch (uMsg) {
    case WM_CREATE:
        hwndText = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
                                10, 10, 400, 300, hwnd, NULL, NULL, NULL);
        SetWindowText(hwndText, TestBalancedParentheses().c_str());
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Test Case Results", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 400,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
