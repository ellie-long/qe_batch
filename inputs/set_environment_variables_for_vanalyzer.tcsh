#!/bin/tcsh
#setenv ROOTSYS		/u/apps/root/5.26-00-64bit/root
#setenv ROOTSYS		/u/apps/root/5.34.01/root
#source /u/apps/root/PRO/setroot_CUE
source /u/apps/root/5.34.36/setroot_CUE
#setenv DISPLAY localhost:0.0
setenv ANALYZER		/u/home/ellie/analyzer-1.5.23
setenv ELLANA		/w/halla-scifs17exp/e05102/disk1/ellie/batch/inputs/ellana
setenv PATH		${ROOTSYS}/bin:${ANALYZER}:${PATH}   
#setenv DB_DIR		${ANALYZER}/DB:${ELLANA}/DB
setenv DB_DIR		${ELLANA}/DB
# setenv LD_LIBRARY_PATH	${ROOTSYS}/lib:${ANALYZER}/
setenv EXPERIMENT	e05102
setenv MYSQL		/apps/mysql
# setenv LD_LIBRARY_PATH	${ROOTSYS}/lib:${ANALYZER}:${MYSQL}/lib/mysql:${LD_LIBRARY_PATH}
setenv LD_LIBRARY_PATH	${ROOTSYS}/lib:${ANALYZER}:${MYSQL}/lib/mysql:${ELLANA}:${LD_LIBRARY_PATH}
