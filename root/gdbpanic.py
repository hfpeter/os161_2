# gdb_script.py
import gdb

class PanicBreakpoint(gdb.Breakpoint):
    def __init__(self):
        super(PanicBreakpoint, self).__init__("panic", gdb.BP_BREAKPOINT)
        
    def stop(self):
        # 检查是否遇到 "panic: Assertion failed"
        if "panic: Assertion failed" in gdb.execute("echo $pc", to_string=True):
            gdb.execute("bt")  # 打印堆栈跟踪
        return False  # 继续执行程序

PanicBreakpoint()
