import subprocess
import sys

cmd = ['python', 'testing_tool.py', '1']
#cmd += ['-monitor', '-3' ] # position relative to mouse cursor
#cmd += ['-layout', '1' ] # specify top left corner of the menu
#cmd += ['-width', str(width) ]
#cmd += ['-xoffset', str(menu_x), '-yoffset', str(menu_y) ]
#cmd += self.rofi_args
#cmd += additional_args
rofi = subprocess.Popen(cmd,stdout=subprocess.PIPE,stdin=subprocess.PIPE)
rofi.stdin.write("1 2 3\n")
rofi.stdin.flush()
foo = rofi.stdout.read()
print foo

rofi.stdin.close()
rofi.wait() 


 
