# 'Launch Docker Image for windows'
How Open and mount docker image at project root using CMD

* Use CMD and navigate to the repo then project root.

  docker run -it --rm -v %cd%:/root/ myubuntu 

  * -i        ==> Interactive mode
  * -t        ==> Name of the image: tag
  * --rm      ==> Deconstruct container after closing (runs in background otherwise)
  * -v virtual mount host file system ontop of target container
      * %cd%      ==> host pwd 
      * /root/    ==> Targets absolute directory
  * myubuntu is the target image