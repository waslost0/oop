@echo off

chcp 1251

SET PROGRAM="%~1"
set OUT="%TEMP%\out.txt"
set LOG="%TEMP%\log.txt"

%PROGRAM% 2> %OUT%
fc %OUT% tests\noParams-out.txt
echo Test 1: No params PASSED

%PROGRAM% tests\missing.txt > %OUT%
fc %OUT% tests\fileMissing-out.txt
fc %OUT% tests\fileMissing-out.txt >> %LOG%
echo Test 2: File missing PASSED
echo Test 2: File missing PASSED >> %LOG%

%PROGRAM% tests\matrix1.txt > %OUT% || goto err
fc %OUT% tests\InvertMatrix1-out.txt || goto err
fc %OUT% tests\InvertMatrix1-out.txt >> %LOG% || goto err
echo Test 3: InvertMatrix1 PASSED
echo Test 3: InvertMatrix1 PASSED >> %LOG%

%PROGRAM% tests\matrix2.txt > %OUT%
fc %OUT% tests\InvertMatrix2-out.txt || goto err
fc %OUT% tests\InvertMatrix2-out.txt >> %LOG% || goto err
echo Test 4: InvertMatrix2 PASSED
echo Test 4: InvertMatrix2 PASSED >> %LOG%

%PROGRAM% tests\matrixDeterminantNull.txt > %OUT%
fc %OUT% tests\matrixDeterminantNull-out.txt || goto err
fc %OUT% tests\matrixDeterminantNull-out.txt >> %LOG% || goto err
echo Test 5: matrixDeterminantNull PASSED
echo Test 5: matrixDeterminantNull PASSED >> %LOG%

echo Program testing succeeded
echo Program testing succeeded >> %LOG%
exit 0

:err
echo Program testing failed
echo Program testing failed >> %LOG%
exit 1