#pragma once

#include <delta/protocol/delta_operations.hpp>

#include <delta/chain/evaluator.hpp>

namespace delta { namespace chain {

using namespace delta::protocol;

DELTA_DEFINE_EVALUATOR( account_create )
DELTA_DEFINE_EVALUATOR( account_create_with_delegation )
DELTA_DEFINE_EVALUATOR( account_update )
DELTA_DEFINE_EVALUATOR( transfer )
DELTA_DEFINE_EVALUATOR( transfer_to_vesting )
DELTA_DEFINE_EVALUATOR( witness_update )
DELTA_DEFINE_EVALUATOR( account_witness_vote )
DELTA_DEFINE_EVALUATOR( account_witness_proxy )
DELTA_DEFINE_EVALUATOR( withdraw_vesting )
DELTA_DEFINE_EVALUATOR( set_withdraw_vesting_route )
DELTA_DEFINE_EVALUATOR( comment )
DELTA_DEFINE_EVALUATOR( comment_options )
DELTA_DEFINE_EVALUATOR( delete_comment )
DELTA_DEFINE_EVALUATOR( vote )
DELTA_DEFINE_EVALUATOR( custom )
DELTA_DEFINE_EVALUATOR( custom_json )
DELTA_DEFINE_EVALUATOR( custom_binary )
DELTA_DEFINE_EVALUATOR( pow )
DELTA_DEFINE_EVALUATOR( pow2 )
DELTA_DEFINE_EVALUATOR( feed_publish )
DELTA_DEFINE_EVALUATOR( convert )
DELTA_DEFINE_EVALUATOR( limit_order_create )
DELTA_DEFINE_EVALUATOR( limit_order_cancel )
DELTA_DEFINE_EVALUATOR( report_over_production )
DELTA_DEFINE_EVALUATOR( limit_order_create2 )
DELTA_DEFINE_EVALUATOR( escrow_transfer )
DELTA_DEFINE_EVALUATOR( escrow_approve )
DELTA_DEFINE_EVALUATOR( escrow_dispute )
DELTA_DEFINE_EVALUATOR( escrow_release )
DELTA_DEFINE_EVALUATOR( claim_account )
DELTA_DEFINE_EVALUATOR( create_claimed_account )
DELTA_DEFINE_EVALUATOR( request_account_recovery )
DELTA_DEFINE_EVALUATOR( recover_account )
DELTA_DEFINE_EVALUATOR( change_recovery_account )
DELTA_DEFINE_EVALUATOR( transfer_to_savings )
DELTA_DEFINE_EVALUATOR( transfer_from_savings )
DELTA_DEFINE_EVALUATOR( cancel_transfer_from_savings )
DELTA_DEFINE_EVALUATOR( decline_voting_rights )
DELTA_DEFINE_EVALUATOR( reset_account )
DELTA_DEFINE_EVALUATOR( set_reset_account )
DELTA_DEFINE_EVALUATOR( claim_reward_balance )
#ifdef DELTA_ENABLE_SMT
DELTA_DEFINE_EVALUATOR( claim_reward_balance2 )
#endif
DELTA_DEFINE_EVALUATOR( delegate_vesting_shares )
DELTA_DEFINE_EVALUATOR( witness_set_properties )
#ifdef DELTA_ENABLE_SMT
DELTA_DEFINE_EVALUATOR( smt_setup )
DELTA_DEFINE_EVALUATOR( smt_cap_reveal )
DELTA_DEFINE_EVALUATOR( smt_refund )
DELTA_DEFINE_EVALUATOR( smt_setup_emissions )
DELTA_DEFINE_EVALUATOR( smt_set_setup_parameters )
DELTA_DEFINE_EVALUATOR( smt_set_runtime_parameters )
DELTA_DEFINE_EVALUATOR( smt_create )
#endif

} } // delta::chain
