

# 初始化触发次数计数器

#mips-harvard-os161-gdb -x debug_script.gdb kernel

set $count = 0
# 设置断点在 sys_fork 函数
#break fork.c:165
#break fd_create
#b sys_fork
#break panic

break sys_fork

commands 1
    printf "----------------kkkkkkkkk-------------------\n"
    printf " thread_fork breakpoint hit, curthread->t_proc->p_addrspace: %p\n", curthread->t_proc->p_addrspace
    break thread_fork
    commands 2
        break thread_make_runnable
        printf "----------------kkkkkkkkk-------------------\n"
        printf " thread_fork breakpoint hit, curthread->t_proc->p_addrspace: %p\n", curthread->t_proc->p_addrspace
    end
end
# 当程序在 sys_fork 断点处暂停时，删除断点
#delete breakpoints 1



define hook-next
    print curthread->t_proc->p_addrspace
end
b thread.c:561
commands 3
    printf " thread_fork breakpoint hit, curthread->t_proc->p_addrspace: %p\n", curthread->t_proc->p_addrspace
end
break fork_child_return
commands 4
    printf " thread_fork breakpoint hit, curthread->t_proc->p_addrspace: %p\n", curthread->t_proc->p_addrspace
end
commands 5
    printf  "thread_fork breakpoint hit, curthread->t_proc->p_addrspace: %p\n", curthread->t_proc->p_addrspace
end

# 当程序在断点处停止时，显示调用栈信息
# ??????????,???????
#commands 4
#    #info args
#    printf "----------------kkkkkkkkk-------------------\
#    Breakpoint triggered %d times\n", $count
#    # ???????
#    #set $count = $count + 1
#    #p err
#    # ????????????
#    set backtrace limit 0    
#    bt
#end

# 启动程序
#c


