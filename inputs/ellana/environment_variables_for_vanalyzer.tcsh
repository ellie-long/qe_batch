# setenv ROOTSYS		/u/apps/root/5.26-00-64bit/root
source /u/apps/root/PRO/setroot_CUE
setenv ANALYZER		/home/ellie/analyzer-1.5.23
setenv ELLANA		/lustre/expphy/work/halla/e05102/ellie/batch/inputs/ellana
setenv PATH		${ROOTSYS}/bin:${ANALYZER}:${PATH}   
#setenv DB_DIR		${ANALYZER}/DB
setenv DB_DIR		${ELLANA}/DB
# setenv LD_LIBRARY_PATH	${ROOTSYS}/lib:${ANALYZER}/
setenv EXPERIMENT	e05102
setenv MYSQL		/apps/mysql
# setenv LD_LIBRARY_PATH	${ROOTSYS}/lib:${ANALYZER}:${MYSQL}/lib/mysql:${LD_LIBRARY_PATH}
setenv LD_LIBRARY_PATH	${ROOTSYS}/lib:${ANALYZER}:${MYSQL}/lib/mysql
