@echo off
set PROGRAM="%~1"
set OUT="%TEMP%\output.txt"
set LOG="%TEMP%\log.txt"

REM null input
%PROGRAM% > %LOG% && goto err
echo Test 1 passed
echo Test 1 passed >> %LOG%

%PROGRAM% 256 >> %LOG% && goto err
echo Test 2 passed
echo Test 2 passed >> %LOG%

%PROGRAM% Hello >> %LOG% && goto err
echo Test 3 passed
echo Test 3 passed >> %LOG%


%PROGRAM% 1 > %OUT% || goto err
fc.exe 1.txt %OUT% >> %LOG% || goto err
echo Test 4 passed
echo Test 4 passed >> %LOG%

%PROGRAM% 2 > %OUT% || goto err
fc.exe 2.txt %OUT% >> %LOG% || goto err
echo Test 5 passed
echo Test 5 passed >> %LOG%


%PROGRAM% 4 > %OUT%  || goto err
fc.exe 4.txt %OUT% >> %LOG% || goto err
echo Test 6 passed
echo Test 6 passed >> %LOG%


%PROGRAM% 23 > %OUT% || goto err
fc.exe 23.txt %OUT% >> %LOG% || goto err
echo Test 7 passed
echo Test 7 passed >> %LOG%

%PROGRAM% 16 > %OUT% || goto err
fc.exe 16.txt %OUT% >> %LOG% || goto err
echo Test 8 passed
echo Test 8 passed >> %LOG%

%PROGRAM% 32 > %OUT% || goto err
fc.exe 32.txt %OUT% >> %LOG% || goto err
echo Test 9 passed
echo Test 9 passed >> %LOG%

%PROGRAM% 64 > %OUT% || goto err
fc.exe 64.txt %OUT% >> %LOG% || goto err
echo Test 10 passed
echo Test 10 passed >> %LOG%

%PROGRAM% 150 > %OUT%  || goto err
fc.exe 150.txt %OUT% >> %LOG% || goto err
echo Test 11 passed
echo Test 11 passed >> %LOG%


echo Program testing succeeded
echo Program testing succeeded >> %LOG%
exit 0

:err
echo Program testing failed
echo Program testing failed >> %LOG%
exit 1
