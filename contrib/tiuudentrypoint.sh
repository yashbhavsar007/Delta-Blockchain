#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start deltad traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/deltad
  cp /usr/local/bin/delta-sv-run.sh /etc/service/deltad/run
  chmod +x /etc/service/deltad/run
  runsv /etc/service/deltad
elif [[ "$IS_TESTNET" ]]; then
  /usr/local/bin/pulltestnetscripts.sh
else
  /usr/local/bin/startpaasdeltad.sh
fi
