### 命令

git branch 创建分支

git checkout 切换分支

git rebase 将所在分支移到某分支后面

- HEAD(当前所在的位置)

  我们首先看一下 “HEAD”。 HEAD 是一个对当前检出记录的符号引用 —— 也就是指向你正在其基础上进行工作的提交记录。
  HEAD 总是指向当前分支上最近一次提交记录。大多数修改提交树的 Git 命令都是从改变 HEAD 的指向开始的。
  HEAD 通常情况下是指向分支名的（如 bugFix）。在你提交时，改变了 bugFix 的状态，这一变化通过 HEAD 变得可见。

git checkout ^ 切换到某分支的上一个记录

~后面接数字n，相当于n个`^`

git branch -f master 将master**分支**强制移动到某个位置,不可以用此命令移动HEAD

git reset reset后更改还在，但是commit已经没了。无法改变远程分支。

git revert 这种方法其实是提交一个新的commit从而将上一次commit取消/抵消掉。

git cherry-pick <提交号> 可以加多个记录，会把记录全部复制到当前分支。

git rebase –interactive/-i UI界面

git diff 查看尚未暂存(add)的文件更新了哪些部分 此命令比较的是工作目录中当前文件和暂存区域快照之间的差异， 也就是修改之后还没有暂存起来的变化内容。

git diff –cached/–staged 查看已暂存的将要添加到下次提交里的内容