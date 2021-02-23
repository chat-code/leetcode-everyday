# leetcode-everyday
一起每天刷题～

## 使用选题脚本

为「今天」随机选一道题。若今天已选，则从「昨天」开始依次尝试补签。默认最多补签过去 30 天，可通过选项 `--past=<days>` 修改

```
# 随机选题
python3 picker.py random

# 随机选题，设置最长补签 90 天
python3 picker.py random --past=90
```

查看完整用法
```
python3 picker.py -h
```
