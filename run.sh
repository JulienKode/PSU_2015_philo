LD_LIBRARY_PATH=`pwd`/lib
export LD_LIBRARY_PATH
LD_PRELOAD=libriceferee.so ./philo -p $1 -e $2
