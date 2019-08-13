/*
 * Copyright (c) 2016 Deltait, Inc., and contributors.
 */
#pragma once
#include <delta/protocol/hardfork.hpp>

// WARNING!
// Every symbol defined here needs to be handled appropriately in get_config.cpp
// This is checked by get_config_check.sh called from Dockerfile

#ifdef IS_TEST_NET
#define DELTA_BLOCKCHAIN_VERSION              ( version(0, 21, 0) )

#define DELTA_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define DELTA_INIT_PUBLIC_KEY_STR             (std::string( delta::protocol::public_key_type(DELTA_INIT_PRIVATE_KEY.get_public_key()) ))
#define DELTA_CHAIN_ID (fc::sha256::hash("testnet"))
#define DELTA_ADDRESS_PREFIX                  "TST"

#define DELTA_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define DELTA_MINING_TIME                     (fc::time_point_sec(1451606400))
#define DELTA_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define DELTA_CASHOUT_WINDOW_SECONDS_PRE_HF12 (DELTA_CASHOUT_WINDOW_SECONDS)
#define DELTA_CASHOUT_WINDOW_SECONDS_PRE_HF17 (DELTA_CASHOUT_WINDOW_SECONDS)
#define DELTA_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define DELTA_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define DELTA_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define DELTA_UPVOTE_LOCKOUT_SECONDS          (60*5)    /// 5 minutes
#define DELTA_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define DELTA_MIN_ACCOUNT_CREATION_FEE          0
#define DELTA_MAX_ACCOUNT_CREATION_FEE          int64_t(1000000000)

#define DELTA_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define DELTA_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define DELTA_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define DELTA_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#define DELTA_INIT_SUPPLY                     (int64_t( 250 ) * int64_t( 1000000 ) * int64_t( 1000 ))

/// Allows to limit number of total produced blocks.
#define TESTNET_BLOCK_LIMIT                   (3000000)

#else // IS LIVE DELTA NETWORK

#define DELTA_BLOCKCHAIN_VERSION              ( version(0, 20, 9) )

#define DELTA_INIT_PUBLIC_KEY_STR             "DEL7ybo1ERDBkPptuYyWeT4VabrxVEyLhBCMrjmDtQP9uDAwy67TG"	
#define DELTA_CHAIN_ID (fc::sha256::hash("delta"))
#define DELTA_ADDRESS_PREFIX                  "DEL"

#define DELTA_GENESIS_TIME                    (fc::time_point_sec(1458835200))
#define DELTA_MINING_TIME                     (fc::time_point_sec(1458838800))
#define DELTA_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24)    /// 1 day
#define DELTA_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*12)    /// 12 hours
#define DELTA_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define DELTA_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define DELTA_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define DELTA_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define DELTA_UPVOTE_LOCKOUT_SECONDS          (60*60*12)    /// 12 hours
#define DELTA_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define DELTA_MIN_ACCOUNT_CREATION_FEE           1
#define DELTA_MAX_ACCOUNT_CREATION_FEE           int64_t(1000000000)

#define DELTA_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define DELTA_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define DELTA_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define DELTA_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 3186477

#define DELTA_INIT_SUPPLY                     (int64_t( 200 ) * int64_t( 1000000 ) * int64_t( 1000 ))

#endif

#define VESTS_SYMBOL  (delta::protocol::asset_symbol_type::from_asset_num( DELTA_ASSET_NUM_VESTS ) )
#define DELTA_SYMBOL  (delta::protocol::asset_symbol_type::from_asset_num( DELTA_ASSET_NUM_DELTA ) )
#define DBD_SYMBOL    (delta::protocol::asset_symbol_type::from_asset_num( DELTA_ASSET_NUM_DBD ) )

#define DELTA_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( DELTA_BLOCKCHAIN_VERSION ) )

#define DELTA_BLOCK_INTERVAL                  3
#define DELTA_BLOCKS_PER_YEAR                 (365*24*60*60/DELTA_BLOCK_INTERVAL)
#define DELTA_BLOCKS_PER_DAY                  (24*60*60/DELTA_BLOCK_INTERVAL)
#define DELTA_START_VESTING_BLOCK             (DELTA_BLOCKS_PER_DAY * 7)
#define DELTA_START_MINER_VOTING_BLOCK        (DELTA_BLOCKS_PER_DAY * 30)

#define DELTA_INIT_MINER_NAME                 "initminer"
#define DELTA_NUM_INIT_MINERS                 1
#define DELTA_INIT_TIME                       (fc::time_point_sec());

#define DELTA_MAX_WITNESSES                   21

#define DELTA_MAX_VOTED_WITNESSES_HF0         19
#define DELTA_MAX_MINER_WITNESSES_HF0         1
#define DELTA_MAX_RUNNER_WITNESSES_HF0        1

#define DELTA_MAX_VOTED_WITNESSES_HF17        20
#define DELTA_MAX_MINER_WITNESSES_HF17        0
#define DELTA_MAX_RUNNER_WITNESSES_HF17       1

#define DELTA_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define DELTA_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define DELTA_MAX_MEMO_SIZE                   2048
#define DELTA_MAX_PROXY_RECURSION_DEPTH       4
#define DELTA_VESTING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define DELTA_VESTING_WITHDRAW_INTERVALS      13
#define DELTA_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval
#define DELTA_MAX_WITHDRAW_ROUTES             10
#define DELTA_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define DELTA_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define DELTA_VOTING_MANA_REGENERATION_SECONDS (5*60*60*24) // 5 day
#define DELTA_MAX_VOTE_CHANGES                5
#define DELTA_REVERSE_AUCTION_WINDOW_SECONDS_HF6 (60*30) /// 30 minutes
#define DELTA_REVERSE_AUCTION_WINDOW_SECONDS_HF20 (60*15) /// 15 minutes
#define DELTA_MIN_VOTE_INTERVAL_SEC           3
#define DELTA_VOTE_DUST_THRESHOLD             (50000000)

#define DELTA_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define DELTA_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define DELTA_MIN_REPLY_INTERVAL_HF20         (fc::seconds(3)) // 3 seconds
#define DELTA_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define DELTA_POST_WEIGHT_CONSTANT            (uint64_t(4*DELTA_100_PERCENT) * (4*DELTA_100_PERCENT))// (4*DELTA_100_PERCENT) -> 2 posts per 1 days, average 1 every 12 hours

#define DELTA_MAX_ACCOUNT_WITNESS_VOTES       30

#define DELTA_100_PERCENT                     10000
#define DELTA_1_PERCENT                       (DELTA_100_PERCENT/100)
#define DELTA_DEFAULT_DBD_INTEREST_RATE       (10*DELTA_1_PERCENT) ///< 10% APR

#define DELTA_INFLATION_RATE_START_PERCENT    (1400) // Fixes block 7,000,000 to 9.5%
#define DELTA_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define DELTA_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define DELTA_CONTENT_REWARD_PERCENT          (75*DELTA_1_PERCENT) //75% of inflation, 7.125% inflation
#define DELTA_VESTING_FUND_PERCENT            (15*DELTA_1_PERCENT) //15% of inflation, 1.425% inflation

#define DELTA_MINER_PAY_PERCENT               (DELTA_1_PERCENT) // 1%
#define DELTA_MAX_RATION_DECAY_RATE           (1000000)

#define DELTA_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define DELTA_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define DELTA_MAX_COMMENT_DEPTH_PRE_HF17      6
#define DELTA_MAX_COMMENT_DEPTH               0xffff // 64k
#define DELTA_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define DELTA_MAX_RESERVE_RATIO               (20000)

#define DELTA_CREATE_ACCOUNT_WITH_DELTA_MODIFIER 30
#define DELTA_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define DELTA_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define DELTA_MINING_REWARD                   asset( 1000, DELTA_SYMBOL )
#define DELTA_EQUIHASH_N                      140
#define DELTA_EQUIHASH_K                      6

#define DELTA_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define DELTA_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define DELTA_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define DELTA_LIQUIDITY_REWARD_BLOCKS         (DELTA_LIQUIDITY_REWARD_PERIOD_SEC/DELTA_BLOCK_INTERVAL)
#define DELTA_MIN_LIQUIDITY_REWARD            (asset( 1000*DELTA_LIQUIDITY_REWARD_BLOCKS, DELTA_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define DELTA_MIN_CONTENT_REWARD              DELTA_MINING_REWARD
#define DELTA_MIN_CURATE_REWARD               DELTA_MINING_REWARD
#define DELTA_MIN_PRODUCER_REWARD             DELTA_MINING_REWARD
#define DELTA_MIN_POW_REWARD                  DELTA_MINING_REWARD

#define DELTA_ACTIVE_CHALLENGE_FEE            asset( 2000, DELTA_SYMBOL )
#define DELTA_OWNER_CHALLENGE_FEE             asset( 30000, DELTA_SYMBOL )
#define DELTA_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define DELTA_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define DELTA_POST_REWARD_FUND_NAME           ("post")
#define DELTA_COMMENT_REWARD_FUND_NAME        ("comment")
#define DELTA_RECENT_RSHARES_DECAY_TIME_HF17    (fc::days(30))
#define DELTA_RECENT_RSHARES_DECAY_TIME_HF19    (fc::days(15))
#define DELTA_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**DELTA_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for vesting
#define DELTA_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that DELTA_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define DELTA_APR_PERCENT_SHIFT_PER_BLOCK             87

#define DELTA_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define DELTA_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**DELTA_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define DELTA_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that DELTA_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define DELTA_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x vesting rewards*
#define DELTA_CURATE_APR_PERCENT              3875
#define DELTA_CONTENT_APR_PERCENT             3875
#define DELTA_LIQUIDITY_APR_PERCENT            750
#define DELTA_PRODUCER_APR_PERCENT             750
#define DELTA_POW_APR_PERCENT                  750

#define DELTA_MIN_PAYOUT_DBD                  (asset(20,DBD_SYMBOL))

#define DELTA_DBD_STOP_PERCENT_HF14           (5*DELTA_1_PERCENT ) // Stop printing DBD at 5% Market Cap
#define DELTA_DBD_STOP_PERCENT_HF20           (10*DELTA_1_PERCENT ) // Stop printing DBD at 10% Market Cap
#define DELTA_DBD_START_PERCENT_HF14          (2*DELTA_1_PERCENT) // Start reducing printing of DBD at 2% Market Cap
#define DELTA_DBD_START_PERCENT_HF20          (9*DELTA_1_PERCENT) // Start reducing printing of DBD at 9% Market Cap

#define DELTA_MIN_ACCOUNT_NAME_LENGTH          3
#define DELTA_MAX_ACCOUNT_NAME_LENGTH         16

#define DELTA_MIN_PERMLINK_LENGTH             0
#define DELTA_MAX_PERMLINK_LENGTH             256
#define DELTA_MAX_WITNESS_URL_LENGTH          2048

#define DELTA_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define DELTA_MAX_SATOSHIS                    int64_t(4611686018427387903ll)
#define DELTA_MAX_SIG_CHECK_DEPTH             2
#define DELTA_MAX_SIG_CHECK_ACCOUNTS          125

#define DELTA_MIN_TRANSACTION_SIZE_LIMIT      1024
#define DELTA_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define DELTA_DBD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define DELTA_MAX_TRANSACTION_SIZE            (1024*64)
#define DELTA_MIN_BLOCK_SIZE_LIMIT            (DELTA_MAX_TRANSACTION_SIZE)
#define DELTA_MAX_BLOCK_SIZE                  (DELTA_MAX_TRANSACTION_SIZE*DELTA_BLOCK_INTERVAL*2000)
#define DELTA_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define DELTA_MIN_BLOCK_SIZE                  115
#define DELTA_BLOCKS_PER_HOUR                 (60*60/DELTA_BLOCK_INTERVAL)
#define DELTA_FEED_INTERVAL_BLOCKS            (DELTA_BLOCKS_PER_HOUR)
#define DELTA_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
#define DELTA_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
#define DELTA_MAX_FEED_AGE_SECONDS            (60*60*24*7) // 7 days
#define DELTA_MIN_FEEDS                       (1) /// protects the network from conversions before price has been established
#define DELTA_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define DELTA_CONVERSION_DELAY                (fc::hours(DELTA_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define DELTA_MIN_UNDO_HISTORY                10
#define DELTA_MAX_UNDO_HISTORY                10000

#define DELTA_MIN_TRANSACTION_EXPIRATION_LIMIT (DELTA_BLOCK_INTERVAL * 5) // 5 transactions per block
#define DELTA_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define DELTA_BLOCKCHAIN_PRECISION_DIGITS     3
#define DELTA_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define DELTA_MAX_AUTHORITY_MEMBERSHIP        40
#define DELTA_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define DELTA_MAX_URL_LENGTH                  127

#define DELTA_IRREVERSIBLE_THRESHOLD          (75 * DELTA_1_PERCENT)

#define DELTA_VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define DELTA_VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

#define DELTA_INITIAL_VOTE_POWER_RATE (40)
#define DELTA_REDUCED_VOTE_POWER_RATE (10)

#define DELTA_MAX_LIMIT_ORDER_EXPIRATION     (60*60*24*28) // 28 days
#define DELTA_DELEGATION_RETURN_PERIOD_HF0   (DELTA_CASHOUT_WINDOW_SECONDS)
#define DELTA_DELEGATION_RETURN_PERIOD_HF20  (DELTA_VOTING_MANA_REGENERATION_SECONDS)

#define DELTA_RD_MIN_DECAY_BITS               6
#define DELTA_RD_MAX_DECAY_BITS              32
#define DELTA_RD_DECAY_DENOM_SHIFT           36
#define DELTA_RD_MAX_POOL_BITS               64
#define DELTA_RD_MAX_BUDGET_1                ((uint64_t(1) << (DELTA_RD_MAX_POOL_BITS + DELTA_RD_MIN_DECAY_BITS - DELTA_RD_DECAY_DENOM_SHIFT))-1)
#define DELTA_RD_MAX_BUDGET_2                ((uint64_t(1) << (64-DELTA_RD_DECAY_DENOM_SHIFT))-1)
#define DELTA_RD_MAX_BUDGET_3                (uint64_t( std::numeric_limits<int32_t>::max() ))
#define DELTA_RD_MAX_BUDGET                  (int32_t( std::min( { DELTA_RD_MAX_BUDGET_1, DELTA_RD_MAX_BUDGET_2, DELTA_RD_MAX_BUDGET_3 } )) )
#define DELTA_RD_MIN_DECAY                   (uint32_t(1) << DELTA_RD_MIN_DECAY_BITS)
#define DELTA_RD_MIN_BUDGET                  1
#define DELTA_RD_MAX_DECAY                   (uint32_t(0xFFFFFFFF))

#define DELTA_ACCOUNT_SUBSIDY_PRECISION      (DELTA_100_PERCENT)

// We want the global subsidy to run out first in normal (Poisson)
// conditions, so we boost the per-witness subsidy a little.
#define DELTA_WITNESS_SUBSIDY_BUDGET_PERCENT (125 * DELTA_1_PERCENT)

// Since witness decay only procs once per round, multiplying the decay
// constant by the number of witnesses means the per-witness pools have
// the same effective decay rate in real-time terms.
#define DELTA_WITNESS_SUBSIDY_DECAY_PERCENT  (DELTA_MAX_WITNESSES * DELTA_100_PERCENT)

// 347321 corresponds to a 5-day halflife
#define DELTA_DEFAULT_ACCOUNT_SUBSIDY_DECAY  (347321)
// Default rate is 0.5 accounts per block
#define DELTA_DEFAULT_ACCOUNT_SUBSIDY_BUDGET (797)
#define DELTA_DECAY_BACKSTOP_PERCENT         (90 * DELTA_1_PERCENT)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define DELTA_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define DELTA_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define DELTA_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define DELTA_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define DELTA_ROOT_POST_PARENT                (account_name_type())
///@}

#ifdef DELTA_ENABLE_SMT

#define SMT_MAX_VOTABLE_ASSETS 2
#define SMT_VESTING_WITHDRAW_INTERVAL_SECONDS   (60*60*24*7) /// 1 week per interval
#define SMT_UPVOTE_LOCKOUT                      (60*60*12)  /// 12 hours

#endif /// DELTA_ENABLE_SMT

