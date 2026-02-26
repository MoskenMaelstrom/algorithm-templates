@echo off
:: 定位到你的代码文件夹（请把下面的路径换成你真实的文件夹路径）
cd /d "C:\Users\你的用户名\Desktop\你的文件夹名"

:: 添加所有更改到暂存区
git add .

:: 提交更改，备注包含当前的日期和时间
git commit -m "Auto update"

:: 推送到 GitHub (假设你的分支叫 main)
git push origin main

exit