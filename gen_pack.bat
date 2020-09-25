@ECHO OFF

REM Batch File for Generating a Software Pack

REM *****************
REM   Remove any existing error log file
REM *****************
DEL /q gen_pack_err.log

REM *****************
REM   Remove unused files
REM *****************
RD /q /s .\Files\MDK\pdmc_example\DebugConfig
RD /q /s .\Files\MDK\pdmc_example\Listings
RD /q /s .\Files\MDK\pdmc_example\Objects
RD /q /s .\Files\MDK\pdmc_example\RTE\_pdmc_example
RD /q /s .\Files\MDK\pdmc_example\RTE\IoT_Utility

REM *****************
REM   Rename GUI option file
REM *****************
SET guifilename="pdmc_example.uvguix"
IF EXIST .\Files\MDK\pdmc_example\%guifilename%.%USERNAME% (
    IF EXIST .\Files\MDK\pdmc_example\%guifilename% (
        DEL /q .\Files\MDK\pdmc_example\%guifilename%
    )
    RENAME .\Files\MDK\pdmc_example\pdmc_example.uvguix.%USERNAME% pdmc_example.uvguix
)

REM *****************
REM   Check for a single PDSC file
REM *****************
SET count=0
FOR %%x IN (*.pdsc) DO SET /a count+=1
IF NOT "%count%"=="1" GOTO ErrPDSC

REM *****************
REM   Set name of PDSC file to be packed
REM *****************
DIR /b *.pdsc > PDSCName.txt
SET /p PDSCName=<PDSCName.txt
DEL /q PDSCName.txt

REM *****************
REM   Copy PDSC file to Files directory
REM *****************
COPY /y %PDSCName% Files

REM ************
REM   Checking
REM ************
.\PackChk.exe .\Files\%PDSCName% -n MyPackName.txt

REM ************
REM   Check if PackChk.exe has completed successfully
REM ************
IF %errorlevel% neq 0 GOTO ErrPackChk

REM ************
REM   Pipe Pack's Name into Variable
REM ************
SET /p PackName=<MyPackName.txt
DEL /q MyPackName.txt

REM ************
REM   Packing
REM ************
PUSHD Files
"C:\Program Files\7-Zip\7z.exe" a %PackName% -tzip
MOVE %PackName% ..\
POPD
GOTO End

:ErrPDSC
ECHO There is more than one PDSC file present! >> gen_pack_err.log
EXIT /b

:ErrPackChk
ECHO PackChk.exe has encountered an error! >> gen_pack_err.log
EXIT /b

:End
ECHO End of batch file.