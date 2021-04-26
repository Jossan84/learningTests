Set oShell = CreateObject("WScript.Shell")

While True
	oShell.SendKeys "{F5}"
	oShell.SendKeys "{SCROLLLOCK}"
	WScript.Sleep 30000 REM ms
WEnd