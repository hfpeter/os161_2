

# 初始化触发次数计数器

# mips-harvard-os161-gdb -x debug_script.gdb kernel



#break sys_fork 
#break thread_fork
##break fork.c:
#break hardclock
#break child_forkentry
#break thread_make_runnable
#break panic
#
#break proc_create
#break pid_alloc

break vfs_bootstrap
break vfs_biglock_acquire
break lock_acquire
break spinlock_release
disable 1       
disable 2
#
disable 3
disable 4
#disable 5
#disable 6
#disable 7
#disable 8
###============

###########
commands 1
    print curthread->t_proc->p_addrspace
    print curthread->t_proc->p_addrspace
    enable 2
end
commands 2
    print curthread->t_proc->p_addrspace
    enable 3
    #enable 4   
end
commands 3
    print curthread->t_proc->p_addrspace
    enable 4
    enable 5
end
commands 4
    print curthread->t_proc->p_addrspace
    #enable 5
end
commands 5
    print curthread->t_proc->p_addrspace
    #enable 5
end
define hook-next
    #print curthread->t_proc->p_addrspace
end


