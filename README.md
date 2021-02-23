# leetcode-everyday
一起每天刷题～

## 使用选题脚本

为「今天」选一道题。若今天已经宣过，则从「昨天」开始依次尝试补签。

```
# 手动选题（会提示输入 leetcode id）
python3 picker.py choose

# 随机选题
python3 picker.py random

# 设置最长补签 90 天，默认为 30 天
python3 picker.py (choose|random) --past=90
```

查看完整用法
```
python3 picker.py -h
```
