# LinuxParalellMarathon
12hでLinux並行プログラミング入門をやる会

## 実行の仕方


```bash
# CentOSのイメージ取得
$ docker pull centos:7

# 名前付けてコンテナ作成
$ docker run -it -d --name linuxpg centos:7

# 実行
# rmはコンテナから抜けた時に、コンテナを削除する
# wオプションはコンテナに入るときのカレントディレクトリの設定
# mountオプションは、source（コンテナ使うホスト）とtarget(コンテナ内のフォルダ）をbindする
docker run -it --rm -w /home/linux --mount type=bind,source=$(pwd),target=/home/linux linuxpg bash
```
