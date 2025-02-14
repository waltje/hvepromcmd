/*
 *   File:   util.c
 *   Author: Matthew Millman (inaxeon@hotmail.com)
 *
 *   1702A/270x/TMS2716/MCM6876x/MCS48 Programmer
 *
 *   This is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 2 of the License, or
 *   (at your option) any later version.
 *   This software is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *   You should have received a copy of the GNU General Public License
 *   along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef _WIN32
# include <windows.h>
# include <conio.h>
#else
# include <fcntl.h>
# include <termios.h>
# include <unistd.h>
# include <errno.h>
# include <sys/ioctl.h>
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "util.h"


#ifndef _WIN32

bool posix_kbhit()
{
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    return byteswaiting > 0;
}

void terminal_set_raw_mode()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Disable echo as well
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void terminal_unset_raw_mode()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

#endif /* _WIN32 */

void terminal_setup(void)
{
#ifdef _WIN32
    HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;

    GetConsoleMode(stdout_handle, &mode);
# ifdef ENABLE_VIRTUIAL_TERMINAL_PROCESSING
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
# endif
    SetConsoleMode(stdout_handle, mode);
#endif /* _WIN32 */
}
