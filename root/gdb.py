import gdb

class BreakpointManager:
    def __init__(self):
        self.breakpoints = []
        self.current_index = 0

    def set_breakpoint(self, location, command):
        bp = gdb.Breakpoint(location)
        bp.silent = True
        bp.command = command
        self.breakpoints.append(bp)
        return bp

    def setup_breakpoints(self):
        # Set the first breakpoint at sys_fork
        self.set_breakpoint('sys_fork', 'python handle_sys_fork()')

    def handle_sys_fork(self):
        # When sys_fork is hit, set the second breakpoint
        if self.current_index == 0:
            self.current_index = 1
            gdb.execute('break thread_fork')
            gdb.execute('continue')

    def handle_thread_fork(self):
        # When thread_fork is hit, set the third breakpoint
        if self.current_index == 1:
            self.current_index = 2
            gdb.execute('break thread_make_runnable')
            gdb.execute('continue')

    def handle_thread_make_runnable(self):
        # When thread_make_runnable is hit, just continue or perform actions
        if self.current_index == 2:
            self.current_index = 3
            # Add any additional commands you want to perform here
            pass

def setup():
    manager = BreakpointManager()
    manager.setup_breakpoints()

    gdb.execute('python setup()')

# Register commands to handle breakpoints
gdb.execute('python def handle_sys_fork(): manager.handle_sys_fork()')
gdb.execute('python def handle_thread_fork(): manager.handle_thread_fork()')
gdb.execute('python def handle_thread_make_runnable(): manager.handle_thread_make_runnable()')

setup()
