SET MyProgram="%~1"
SET OUT="%TEMP%\Out.txt"

REM Copy empty file
%MyProgram% empty.txt "%OUT%" || goto err
fc.exe "%OUT%" answer0.txt || goto err
REM if ERRORLEVEL 1 goto err 

echo Program testing succeeded
exit /B 0

:err
echo Program testing failed
exit /B 1