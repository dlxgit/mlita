REM
Debug\raspil_final.exe tests\test_input1.txt
IF ERRORLEVEL 1 GOTO err
FC /b tests\test_output1.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Debug\raspil_final.exe tests\test_input2.txt
IF ERRORLEVEL 1 GOTO err
FC /b tests\test_output2.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Debug\raspil_final.exe tests\test_input3.txt
IF ERRORLEVEL 1 GOTO err
FC /b tests\test_output3.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Debug\raspil_final.exe tests\test_input4.txt
IF ERRORLEVEL 1 GOTO err
FC /b tests\test_output4.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Debug\raspil_final.exe tests\test_input5_incorrect.txt
IF NOT ERRORLEVEL 1 GOTO err

ECHO Tests are finished successfully.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B