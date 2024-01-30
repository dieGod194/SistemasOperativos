set /p tiempo="tiempo para apagar el equipo: "
set /a cancelar=tiempo-1
shutdown /s /t %tiempo%
timeout /t %cancelar%
shutdown /a
echo apagado cancelado xdd
pause