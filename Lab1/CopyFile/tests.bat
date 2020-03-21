@echo off

SET PROGRAM="%~1"
SET OUT="%TEMP%\output.txt"
SET LOG="%TEMP%\log.txt"


REM Copy empty file
%PROGRAM% empty.txt %OUT% > %LOG% || goto err
fc.exe %OUT% answer0.txt >> %LOG% || goto err
REM if ERRORLEVEL 1 goto err 
echo Test 1 passed
echo Test 1 passed >> %LOG%

REM Copy non empty file
%PROGRAM% not_empty.txt %OUT% >> %LOG% || goto err
fc.exe %OUT% answer1.txt >> %LOG% || goto err
echo Test 2 passed
echo Test 2 passed >> %LOG%

REM Copy missing file 
%PROGRAM% MissingFile.txt %OUT% >> %LOG% && goto err
echo Test 3 passed
echo Test 3 passed >> %LOG%

REM If output file is not specified, program must fail
%PROGRAM% input.txt >> %LOG% && goto err
echo Test 4 passed
echo Test 4 passed >> %LOG%

REM If input and output file is not specified, program must fail
%PROGRAM% >> %LOG% && goto err
echo Test 5 passed
echo Test 5 passed >> %LOG%

REM If 4 arguments 
%PROGRAM% input.txt input.txt output.txt >> %LOG% && goto err
echo Test 6 passed
echo Test 6 passed >> %LOG%

REM multi line file
%PROGRAM% multiline.txt %OUT% >> %LOG% || goto err
fc.exe %OUT% answer2.txt >> %LOG% || goto err
echo Test 7 passed
echo Test 7 passed >> %LOG%

rem ожидаем ненулевой код ошибки при невозможности записи в выходной файл (в исполняемый файл программы)
%PROGRAM% multiline.txt %PROGRAM% > %OUT% && goto err
echo Test 8 passed
echo Test 8 passed >> %LOG%

echo Program testing succeeded
echo Program testing succeeded >> %LOG%
exit /B 0

:err
echo Program testing failed
echo Program testing failed >> %LOG%
exit /B 1