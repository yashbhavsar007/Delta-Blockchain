**Delta Commands**

Initminer Key
```
PRIVATE KEY: 5HtcyQSJxK9BJJXfACU5Fb9kuqJgK1vcQTUnNfmVBzE5GWaBL1P
PUBLIC KEY:  TIU7ybo1ERDBkPptuYyWeT4VabrxVEyLhBCMrjmDtQP9uDAwy67TG
```


**Start server**

```
ubuntu:~$ ssh admuser@162.245.237.98
admuser@162.245.237.98's password:DzhKD3y6BK
```





**To Restart Blockchain**

```
admuser@4031:~$ cd delta_22M/delta_block/ 
admuser@4031:~/delta_22M/delta_block$ cd build/
admuser@4031:~/delta_22M/delta_block/build$ deltad -d smt/
```



**To get account details**


```
admuser@4031:~/delta_22M/delta_block$ cd programs/cli_wallet/
admuser@4031:~/delta_22M/delta_block/programs/cli_wallet$ cli_wallet -s ws://162.245.237.98:9876
locked >>> unlock "rew"

// to get information of initminer’s account
unlocked >>> get_account initminer
```




If getting an error while running cli_wallet -s ws://162.245.237.98:9876 this command try below code


```
Error:
Logging RPC to file: logs/rpc/rpc.log
terminate called after throwing an instance of 'std::runtime_error'
  what():  locale::facet::_S_create_c_locale name not valid
Aborted
```


Solution:


```
admuser@4031:~/delta_22M/delta_block/programs/cli_wallet$ LC_ALL="C"
admuser@4031:~/delta_22M/delta_block/programs/cli_wallet$ export LC_ALL
```



**To transfer balance to another account **



```
// transferring 10.000 DELTA to DESTINATION_ACCOUNT from initminer’s // account
unlocked >>> transfer initminer DESTINATION_ACCOUNT_NAME "10.000 DELTA" "" true

```




**To update price feed in blockchain**

`unlocked >>> publish_feed witminer { "base":"1.000 DBD", "quote":"1.000 DELTA"} true`


**Start witness server**

```
ubuntu:~$ ssh admuser@38.141.45.98
admuser@38.141.45.98's password:fOqezAtO8Z
```




**To restart witness**

```
admuser@5041:~$  cd delta/delta_block/build
admuser@5041:~$  deltad -d smt/
```












