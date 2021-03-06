; Mobile DOAS installer

[Setup]
AppName=MobileDOAS
AppVersion=6.0
DefaultDirName={sd}\MobileDOAS
DefaultGroupName=MobileDOAS
Compression=lzma2
SolidCompression=yes   
UninstallDisplayIcon={app}\MobileDOAS.exe
; "ArchitecturesAllowed=x64" specifies that Setup cannot run on
; anything but x64.
ArchitecturesAllowed=x64
; "ArchitecturesInstallIn64BitMode=x64" requests that the install be
; done in "64-bit mode" on x64, meaning it should use the native
; 64-bit Program Files directory and the 64-bit view of the registry.
ArchitecturesInstallIn64BitMode=x64
DisableDirPage=no

[Files]
Source: "..\x64\Release\MobileDOAS.exe"; DestDir: "{app}" 
Source: "..\doc\MobileDOAS_5_UserManual.pdf"; DestDir: "{app}"
;Source: ".\OmniDriver-2.46-win64-installer.exe"; DestDir: "{app}"

[Icons]
Name: "{group}\MobileDOAS"; Filename: "{app}\MobileDOAS.exe"

[Run]
;Filename: "{app}\OmniDriver-2.46-win64-installer.exe"; Description: "OmniDriver from OceanOptics"; Flags: 64bit 