FROM centos:7

RUN yum -y update && \
    yum groupinstall -y "Development Tools" && \
    yum -y install man-pages && \
    yum -y install man && \
    yum -y --setopt=tsflags='' reinstall man-pages && \
    yum -y install strace

