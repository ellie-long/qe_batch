export DEBUG=0
#export ROOTSYS=/u/apps/root/5.26-00-64bit/root
source /u/apps/root/PRO/setroot_CUE
export ANALYZER=/home/ellie/analyzer-1.5.23
export ELLANA=/work/halla/e05102/disk1/ellie/batch/inputs/ellana
export PATH=${ROOTSYS}/bin:${ANALYZER}:${PATH}   
#export DB_DIR=${ANALYZER}/DB
export DB_DIR=${ELLANA}/DB
# export LD_LIBRARY_PATH=${ROOTSYS}/lib:${ANALYZER}/
export EXPERIMENT=e05102
export MYSQL=/apps/mysql
export LD_LIBRARY_PATH=${ROOTSYS}/lib:${ANALYZER}:${MYSQL}/lib/mysql:${LD_LIBRARY_PATH}
