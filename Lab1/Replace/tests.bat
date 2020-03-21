@echo off

set PROGRAM="%~1"
SET OUT="%TEMP%\output.txt"
SET LOG="%TEMP%\log.txt"


REM Replace '1' to '2' input file is empty
%PROGRAM% TestInput1.txt %OUT% "1" "2" || goto err
fc.exe %OUT% Answer1.txt > %LOG% || goto err 
echo Test 1 passed
echo Test 1 passed >> %LOG%

REM Replase '1' to '2'
%PROGRAM% TestInput2.txt %OUT% "1" "2" || goto err
fc.exe %OUT% Answer2.txt >> %LOG% || goto err
echo Test 2 passed
echo Test 2 passed >> %LOG%

REM Replase 'ma' to 'mama'
%PROGRAM% TestInput3.txt %OUT% "ma" "mama" || goto err
fc.exe %OUT% Answer3.txt >> %LOG% || goto err
echo Test 3 passed
echo Test 3 passed >> %LOG%

REM Replase '1231234' to '8'
%PROGRAM% TestInput4.txt %OUT% "1231234" "8" || goto err
fc.exe %OUT% Answer4.txt >> %LOG% || goto err
echo Test 4 passed
echo Test 4 passed >> %LOG%

REM Replace 'a'
%PROGRAM% TestInput5.txt %OUT% "a" || goto err
fc.exe %OUT% Answer5.txt >> %LOG% || goto err
echo Test 5 passed
echo Test 5 passed >> %LOG%

REM Missing file, program must fail
%PROGRAM% MissingFile.txt "%OUT%" && goto err
echo Test 6 passed
echo Test 6 passed >> %LOG%

REM If 4 arguments
%PROGRAM% TestInput5.txt TestInput5.txt TestInput5.txt && goto err
echo Test 7 passed
echo Test 7 passed >> %LOG%

REM If not output file is not specified, program must fail
%PROGRAM% input.txt && goto err
echo Test 8 passed
echo Test 8 passed >> %LOG%

REM If not output is not specified, program must fail
%PROGRAM% input.txt && goto err
echo Test 9 passed
echo Test 9 passed >> %LOG%

REM Replace 'lorem' to 'Merol' huge file
%PROGRAM% TestInput0.txt %OUT% "lorem" "Merol"|| goto err
fc.exe %OUT% Answer0.txt >> %LOG% || goto err
echo Test 10 passed
echo Test 10 passed >> %LOG%

REM Replace '' to '' 
%PROGRAM% TestInput7.txt %OUT% "" || goto err
fc.exe %OUT% Answer7.txt >> %LOG% || goto err
echo Test 11 passed
echo Test 11 passed >> %LOG%

echo Program testing succeeded
echo Program testing succeeded >> %LOG%
exit 0

:err
echo Program testing failed
echo Program testing failed >> %LOG%
exit 1
