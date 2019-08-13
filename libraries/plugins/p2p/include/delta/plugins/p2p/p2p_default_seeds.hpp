#pragma once

#include <vector>

namespace delta{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed-east.deltait.com:2001",          // deltait
   "seed-central.deltait.com:2001",       // deltait
   "seed-west.deltait.com:2001",          // deltait
   "delta-seed1.abit-more.com:2001",      // abit
   "52.74.152.79:2001",                   // smooth.witness
   "seed.deltad.com:34191",               // roadscape
   "anyx.co:2001",                        // anyx
   "seed.xeldal.com:12150",               // xeldal
   "seed.deltanodes.com:2001",            // wackou
   "seed.liondani.com:2016",              // liondani
   "gtg.delta.house:2001",                // gtg
   "seed.jesta.us:2001",                  // jesta
   "deltad.pharesim.me:2001",             // pharesim
   "5.9.18.213:2001",                     // pfunk
   "lafonadelta.com:2001",                // lafona
   "seed.rossco99.com:2001",              // rossco99
   "delta-seed.altcap.io:40696",          // ihashfury
   "seed.roelandp.nl:2001",               // roelandp
   "delta.global:2001",                   // klye
   "seed.edelta.ws:2001",                 // good-karma
   "seed.timcliff.com:2001",              // timcliff
   "104.199.118.92:2001",                 // clayop
   "seed.deltaviz.com:2001",              // ausbitbank
   "delta-seed.lukestokes.info:2001",     // lukestokes
   "seed.deltaian.info:2001",             // drakos
   "seed.followbtcnews.com:2001",         // followbtcnews
   "node.mahdiyari.info:2001",            // mahdiyari
   "seed.curiedelta.com:2001",            // curie
   "seed.riverdelta.com:2001",            // riverhead
   "148.251.237.104:2001",                // delta-bounty
   "seed1.blockbrothers.io:2001",         // blockbrothers
   "deltaseed-fin.privex.io:2001",        // privex
   "seed.jamzed.pl:2001",                 // jamzed
   "seed1.cryptobot.news:2001",           // libertyranger
   "seed.thecryptodrive.com:2001",        // thecryptodrive
   "seed.brandonfrye.us:2001",            // brandonfrye
   "seed.firepower.ltd:2001"              // firepower
};
#endif

} } } // delta::plugins::p2p
