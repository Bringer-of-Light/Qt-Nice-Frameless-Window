# Qt-Nice-Frameless-Window
Qt Frameless Window for both Windows and OS X, support Aero Snap, drop shadow on Windows, and support Native Style such as round corner, drop shadow on OS X. Based on QMainWindow.

# Screenshots
| Windows | OS X|
|:-------------:|:-------------:|
| ![screenshot on Windows](screenshots/screenshot_win_1.gif)  |![screenshot on OS X](screenshots/screenshot_mac_1.gif) |


# How to use
Just use class "CFramelessWindow" as your base mainwindow class instead of QMainWindow, and Enjoy!

## Method 1
If you want to create a new project, then method 1 should be used.   
1. Create a new Qt subproject project say myproject.pro, just like Qt-Nice-Frameless-Window.pro.
![](screenshots/screenshot_step_10.png) 
2. Copy folder "framelesswindow" and "projectinclude" to myproject path, your project directory structure should be looked like this:   
  -myproject/   
  &nbsp;&nbsp;-myproject.pro   
  &nbsp;&nbsp;-myproject.pro.user   
  &nbsp;&nbsp;-framelesswindow/   
  &nbsp;&nbsp;-projectinclude/  
![](screenshots/screenshot_step_11.png) 
  
3. Add "SUBDIRS += framelesswindow" in myproject.pro and run qmake.
![](screenshots/screenshot_step_12.png) 
4. Add a sub project say myapp.pro to myproject. 

| 1 | 2 |
|:-------------:|:-------------:|
| ![](screenshots/screenshot_step_13.png) | ![](screenshots/screenshot_step_14.png) |

5. Add "myapp.depends = framelesswindow" in myproject.pro and run qmake.
6. Add "include (../projectinclude/common.pri)" in myapp.pro and run qmake.
7. Right click on myapp.pro, and click "add library", a dialog will pop up, choose "interal library" and click next step again and again.

| 1 | 2 | 3 |
|:--:|:--:|:--:|
| ![](screenshots/screenshot_step_15.png) | ![](screenshots/screenshot_step_16.png) | ![](screenshots/screenshot_step_17.png) |
8. After step 7 is done, something will be added into your myapp.pro file automaticly, run qmake again.
![](screenshots/screenshot_step_19.png) 
8. Use class "CFramelessWindow" as your base mainwindow class instead of QMainWindow.
![](screenshots/screenshot_step_18.png) 

## Method 2
If you already have a project say myproject.pro, then method 2 should be used.
1. Copy folder "framelesswindow" and "projectinclude" to myproject path.
2. Add "INCLUDEPATH += $$PWD/framelesswindow" and "DEPENDPATH += $$PWD/framelesswindow" in myproject.pro.
3. Use class "CFramelessWindow" as your base mainwindow class instead of QMainWindow.

# Platform
- Tested with Qt5.9.2.
- Tested on Windows 7 and OS X 10.10.2.
