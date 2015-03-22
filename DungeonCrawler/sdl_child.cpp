// sdl_child.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "sdl_child.h"

#include <SDL.h>
#include "GameTimer.h"
#include "Graphics.h"
#include "game.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
game SDLgame;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);



bool initSDL(HWND hWnd)
{
    //Initialization flag
    bool success = true;

    SDL_Init( SDL_INIT_VIDEO );
    //Graphics::gWindow = SDL_CreateWindow( "DungeonCrawler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    Graphics::gWindow = SDL_CreateWindowFrom(hWnd);
    Graphics::gRenderer = SDL_CreateRenderer( Graphics::gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    SDL_SetRenderDrawColor( Graphics::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "best" );

    return success;
}



BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;
   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, 
                       szTitle, 
                       WS_OVERLAPPEDWINDOW, 
                       CW_USEDEFAULT, 
                       0, 
                       CW_USEDEFAULT, 
                       0, 
                       NULL, 
                       NULL,
                       hInstance,
                       NULL);


   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;
    SDL_Surface* s = SDL_GetWindowSurface(Graphics::gWindow);

    switch (message)
    {
    case WM_COMMAND:
        wmId    = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        break;
    case WM_PAINT:

        hdc = BeginPaint(hWnd, &ps);
        // TODO: Add any drawing code here...
        EndPaint(hWnd, &ps);

        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    } 

    return 0;
}


LRESULT CALLBACK RightWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
    case WM_COMMAND:
        break;
    case WM_PAINT:
        //HDC hDC;
        //PAINTSTRUCT Ps;
        //HPEN hPen;

        //hDC = BeginPaint(hWnd, &Ps);

        //EndPaint(hWnd, &Ps);

        break;
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    } 

    return 0;
}


LRESULT CALLBACK LeftWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
    case WM_COMMAND:
        break;
    case WM_PAINT:
        break;
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    } 

    return 0;
}


// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


ATOM RegisterWindowClass(HINSTANCE hInstance)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style			= CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc	= WndProc;
    wcex.cbClsExtra		= 0;
    wcex.cbWndExtra		= 0;
    wcex.hInstance		= hInstance;
    wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SDL_CHILD));
    wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
    //wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+14);
    wcex.hbrBackground = CreateSolidBrush(RGB(192, 192, 192));
    wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SDL_CHILD);
    wcex.lpszClassName	= szWindowClass;
    wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

 //   wcex.cbSize        = sizeof(WNDCLASSEX);
 //   wcex.style         = 0;
 //   wcex.lpfnWndProc   = WndProc;
 //   wcex.cbClsExtra    = 0;
 //   wcex.cbWndExtra    = 0;
 //   wcex.hInstance     = hInstance;
 //   wcex.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
 //   wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);
 //   wcex.hbrBackground = CreateSolidBrush(RGB(192, 192, 192));//(HBRUSH)(COLOR_WINDOW+1);
 //   wcex.lpszMenuName  = NULL;//MAKEINTRESOURCE(IDC_W32_TEST2);
 //   wcex.lpszClassName = szWindowClass;
 //   wcex.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
	//wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SDL_CHILD);

    if(!RegisterClassEx(&wcex))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    wcex.lpfnWndProc   = LeftWndProc;
    wcex.lpszClassName = "LeftWnd";
    wcex.hbrBackground = CreateSolidBrush(RGB(0, 192, 192));

    if(!RegisterClassEx(&wcex))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    wcex.lpfnWndProc   = RightWndProc;
    wcex.lpszClassName = "RightWnd";
    wcex.hbrBackground = CreateSolidBrush(RGB(192, 0, 192));

    if(!RegisterClassEx(&wcex))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
}


int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
    MSG msg;
    HACCEL hAccelTable;

    // Initialize global strings
    LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadString(hInstance, IDC_SDL_CHILD, szWindowClass, MAX_LOADSTRING);



    HWND hWnd;
    HWND hLeftWnd;
    HWND hRightWnd;
    hInst = hInstance;
    RECT rects;

    RegisterWindowClass(hInstance);

    hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, 
                          szWindowClass, 
                          szTitle, 
                          WS_OVERLAPPEDWINDOW, 
                          CW_USEDEFAULT, 
                          CW_USEDEFAULT, 
                          500, 
                          500, 
                          NULL, 
                          NULL,
                          hInstance,
                          NULL);

   if (!hWnd)
      return FALSE;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);


   GetClientRect(hWnd, &rects);

   int leftWndWidth = rects.right / 4;
   int rightWndHeight = rects.bottom;

   hLeftWnd = CreateWindowEx(WS_EX_CLIENTEDGE, 
                             "LeftWnd", 
                             "", 
                             WS_CHILD | WS_VISIBLE | WS_BORDER,
                             rects.left, 
                             rects.top, 
                             leftWndWidth, 
                             rightWndHeight, 
                             hWnd, 
                             NULL,
                             GetModuleHandle(NULL),
                             NULL);

    if(NULL != hLeftWnd)
    {
        ShowWindow(hLeftWnd, SW_SHOW);
        UpdateWindow(hLeftWnd);
    }

    hRightWnd = CreateWindowEx(WS_EX_CLIENTEDGE, 
                              "RightWnd", 
                              "", 
                              WS_CHILD | WS_VISIBLE | WS_BORDER, 
                              leftWndWidth, 
                              rects.top, 
                              rects.right - leftWndWidth, 
                              rects.bottom, 
                              hWnd, 
                              NULL,
                              GetModuleHandle(NULL),
                              NULL);

    if(NULL != hRightWnd)
    {
        ShowWindow(hRightWnd, SW_SHOW);
        UpdateWindow(hRightWnd);
    }

   initSDL(hRightWnd);
   SDLgame.init();

   hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SDL_CHILD));

   // Main message loop:
   while (GetMessage(&msg, NULL, 0, 0))
   {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        SDLgame.draw();
   }

   return (int) msg.wParam;

}