@echo off

SET PROGRAM="%~1"
SET OUT="%TEMP%\output.txt"


if %PROGRAM%=="" (
	echo Please specify path to program
	exit /B 1
)

REM Copy empty file
%PROGRAM% empty.txt "%OUT%" || goto err
fc.exe "%OUT%" answer0.txt > null|| goto err
REM if ERRORLEVEL 1 goto err 
echo Test 1 passed

REM Copy non empty file
%PROGRAM% not_empty.txt "%OUT%" || goto err
fc.exe "%OUT%" answer1.txt > null|| goto err
echo Test 2 passed

REM Copy missing file 
%PROGRAM% MissingFile.txt "%OUT%" && goto err
echo Test 3 passed

REM If not output file is not specified, program must fail
%PROGRAM% input.txt && goto err
echo Test 4 passed

REM If not input and output file is not specified, program must fail
%PROGRAM% && goto err
echo Test 5 passed

REM If 4 arguments
%PROGRAM% input.txt input.txt output.txt && goto err
echo Test 6 passed

echo Program testing succeeded
exit /B 0

:err
echo Program testing failed
exit /B 1