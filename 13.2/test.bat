REM
Debug\13.2.exe tests\test_1_input.txt
IF NOT ERRORLEVEL 0 GOTO err
FC /b tests\test_1_output.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Debug\13.2.exe tests\test_2_input.txt
IF NOT ERRORLEVEL 0 GOTO err
FC /b tests\test_2_output.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Debug\13.2.exe tests\test_3_max_data_input.txt
IF NOT ERRORLEVEL 0 GOTO err
FC /b tests\test_3_output.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Debug\13.2.exe tests\test_4_input.txt
IF NOT ERRORLEVEL 0 GOTO err
FC /b tests\test_4_output.txt output.txt
IF ERRORLEVEL 1 GOTO err


REM
Debug\13.2.exe tests\test_5_incorrect_input.txt
IF NOT ERRORLEVEL 2 GOTO err
FC /b tests\test_5_output.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Debug\13.2.exe tests\test_6_incorrect_inputFile.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /b tests\test_6_output.txt output.txt
IF ERRORLEVEL 1 GOTO err


ECHO Tests are finished successfully.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B