static pme_sparc_entry_t ultra3plus_pe[] = {
	/* These two must always be first.  */
	{	.pme_name = "Cycle_cnt",
		.pme_desc = "Accumulated cycles",
		.pme_ctrl = PME_CTRL_S0 | PME_CTRL_S1,
		.pme_val = 0x0,
	},
	{	.pme_name = "Instr_cnt",
		.pme_desc = "Number of instructions completed",
		.pme_ctrl = PME_CTRL_S0 | PME_CTRL_S1,
		.pme_val = 0x1,
	},

	/* PIC0 events common to all UltraSPARC processors */
	{
		.pme_name = "Dispatch0_IC_miss",
		.pme_desc = "I-buffer is empty from I-Cache miss",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x2,
	},
	{
		.pme_name = "IC_ref",
		.pme_desc = "I-cache refrences",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x8,
	},
	{
		.pme_name = "DC_rd",
		.pme_desc = "D-cache read references (including accesses that subsequently trap)",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x9,
	},
	{
		.pme_name = "DC_wr",
		.pme_desc = "D-cache store accesses (including cacheable stores that subsequently trap)",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0xa,
	},
	{
		.pme_name = "EC_ref",
		.pme_desc = "E-cache references",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0xc,
	},
	{
		.pme_name = "EC_snoop_inv",
		.pme_desc = "L2-cache invalidates generated from a snoop by a remote processor",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0xe,
	},

	/* PIC1 events common to all UltraSPARC processors */
	{
		.pme_name = "Dispatch0_mispred",
		.pme_desc = "I-buffer is empty from Branch misprediction",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x2,
	},
	{
		.pme_name = "EC_wb",
		.pme_desc = "Dirty sub-blocks that produce writebacks due to L2-cache miss events",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0xd,
	},
	{
		.pme_name = "EC_snoop_cb",
		.pme_desc = "L2-cache copybacks generated from a snoop by a remote processor",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0xe,
	},

	/* PIC0 events common to all UltraSPARC-III/III+/IIIi processors  */
	{
		.pme_name = "Dispatch0_br_target",
		.pme_desc = "I-buffer is empty due to a branch target address calculation",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x3,
	},
	{
		.pme_name = "Dispatch0_2nd_br",
		.pme_desc = "Stall cycles due to having two branch instructions line-up in one 4-instruction group causing the second branch in the group to be re-fetched, delaying it's entrance into the I-buffer",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x4,
	},
	{
		.pme_name = "Rstall_storeQ",
		.pme_desc = "R-stage stall for a store instruction which is the next instruction to be executed, but it stailled due to the store queue being full",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x5,
	},
	{
		.pme_name = "Rstall_IU_use",
		.pme_desc = "R-stage stall for an event that the next instruction to be executed depends on the result of a preceeding integer instruction in the pipeline that is not yet available",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x6,
	},
	{
		.pme_name = "EC_write_hit_RTO",
		.pme_desc = "W-cache exclusive requests that hit L2-cache in S, O, or Os state and thus, do a read-to-own bus transaction",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0xd,
	},
	{
		.pme_name = "EC_rd_miss",
		.pme_desc = "L2-cache miss events (including atomics) from D-cache events",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0xf,
	},
	{
		.pme_name = "PC_port0_rd",
		.pme_desc = "P-cache cacheable FP loads to the first port (general purpose load path to D-cache and P-cache via MS pipeline)",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x10,
	},
	{
		.pme_name = "SI_snoop",
		.pme_desc = "Counts snoops from remote processor(s) including RTS, RTSR, RTO, RTOR, RS, RSR, RTSM, and WS",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x11,
	},
	{
		.pme_name = "SI_ciq_flow",
		.pme_desc = "Counts system clock cycles when the flow control (PauseOut) signal is asserted",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x12,
	},
	{
		.pme_name = "SI_owned",
		.pme_desc = "Counts events where owned_in is asserted on bus requests from the local processor",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x13,
	},
	{
		.pme_name = "SW_count0",
		.pme_desc = "Counts software-generated occurrences of 'sethi %hi(0xfc000), %g0' instruction",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x14,
	},
	{	.pme_name = "IU_Stat_Br_miss_taken",
		.pme_desc = "Retired branches that were predicted to be taken, but in fact were not taken",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x15,
	},
	{	.pme_name = "IU_Stat_Br_Count_taken",
		.pme_desc = "Retired taken branches",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x16,
	},
	{
		.pme_name = "Dispatch0_rs_mispred",
		.pme_desc = "I-buffer is empty due to a Return Address Stack misprediction",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x4,
	},
	{
		.pme_name = "FA_pipe_completion",
		.pme_desc = "Instructions that complete execution on the FPG ALU pipelines",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x18,
	},

	/* PIC1 events common to all UltraSPARC-III/III+/IIIi processors  */
	{
		.pme_name = "IC_miss_cancelled",
		.pme_desc = "I-cache misses cancelled due to mis-speculation, recycle, or other events",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x3,
	},
	{
		.pme_name = "Re_FPU_bypass",
		.pme_desc = "Stall due to recirculation when an FPU bypass condition that does not have a direct bypass path occurs",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x5,
	},
	{
		.pme_name = "Re_DC_miss",
		.pme_desc = "Stall due to loads that miss D-cache and get recirculated",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x6,
	},
	{
		.pme_name = "Re_EC_miss",
		.pme_desc = "Stall due to loads that miss L2-cache and get recirculated",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x7,
	},
	{
		.pme_name = "IC_miss",
		.pme_desc = "I-cache misses, including fetches from mis-speculated execution paths which are later cancelled",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x8,
	},
	{
		.pme_name = "DC_rd_miss",
		.pme_desc = "Recirculated loads that miss the D-cache",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x9,
	},
	{
		.pme_name = "DC_wr_miss",
		.pme_desc = "D-cache store accesses that miss D-cache",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0xa,
	},
	{
		.pme_name = "Rstall_FP_use",
		.pme_desc = "R-stage stall for an event that the next instruction to be executed depends on the result of a preceeding floating-point instruction in the pipeline that is not yet available",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0xb,
	},
	{
		.pme_name = "EC_misses",
		.pme_desc = "E-cache misses",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0xc,
	},
	{
		.pme_name = "EC_ic_miss",
		.pme_desc = "L2-cache read misses from I-cache requests",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0xf,
	},
	{
		.pme_name = "Re_PC_miss",
		.pme_desc = "Stall due to recirculation when a prefetch cache miss occurs on a prefetch predicted second load",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x10,
	},
	{
		.pme_name = "ITLB_miss",
		.pme_desc = "I-TLB miss traps taken",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x11,
	},
	{
		.pme_name = "DTLB_miss",
		.pme_desc = "Memory reference instructions which trap due to D-TLB miss",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x12,
	},
	{
		.pme_name = "WC_miss",
		.pme_desc = "W-cache misses",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x13,
	},
	{
		.pme_name = "WC_snoop_cb",
		.pme_desc = "W-cache copybacks generated by a snoop from a remote processor",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x14,
	},
	{
		.pme_name = "WC_scrubbed",
		.pme_desc = "W-cache hits to clean lines",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x15,
	},
	{
		.pme_name = "WC_wb_wo_read",
		.pme_desc = "W-cache writebacks not requiring a read",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x16,
	},
	{
		.pme_name = "PC_soft_hit",
		.pme_desc = "FP loads that hit a P-cache line that was prefetched by a software-prefetch instruction",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x18,
	},
	{
		.pme_name = "PC_snoop_inv",
		.pme_desc = "P-cache invalidates that were generated by a snoop from a remote processor and stores by a local processor",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x19,
	},
	{
		.pme_name = "PC_hard_hit",
		.pme_desc = "FP loads that hit a P-cache line that was prefetched by a hardware prefetch",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x1a,
	},
	{
		.pme_name = "PC_port1_rd",
		.pme_desc = "P-cache cacheable FP loads to the second port (memory and out-of-pipeline instruction execution loads via the A0 and A1 pipelines)",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x1b,
	},
	{
		.pme_name = "SW_count1",
		.pme_desc = "Counts software-generated occurrences of 'sethi %hi(0xfc000), %g0' instruction",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x1c,
	},
	{	.pme_name = "IU_Stat_Br_miss_untaken",
		.pme_desc = "Retired branches that were predicted to be untaken, but in fact were taken",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x1d,
	},
	{	.pme_name = "IU_Stat_Br_Count_untaken",
		.pme_desc = "Retired untaken branches",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x1e,
	},
	{
		.pme_name = "PC_MS_miss",
		.pme_desc = "FP loads through the MS pipeline that miss P-cache",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x1f,
	},
	{
		.pme_name = "Re_RAW_miss",
		.pme_desc = "Stall due to recirculation when there is a load in the E-stage which has a non-bypassable read-after-write hazard with an earlier store instruction",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x26,
	},
	{
		.pme_name = "FM_pipe_completion",
		.pme_desc = "Instructions that complete execution on the FPG Multiply pipelines",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x27,
	},


	/* PIC0 memory controller events common to UltraSPARC-III/III+ processors */
	{
		.pme_name = "MC_reads_0",
		.pme_desc = "Read requests completed to memory bank 0",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x20,
	},
	{
		.pme_name = "MC_reads_1",
		.pme_desc = "Read requests completed to memory bank 1",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x21,
	},
	{
		.pme_name = "MC_reads_2",
		.pme_desc = "Read requests completed to memory bank 2",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x22,
	},
	{
		.pme_name = "MC_reads_3",
		.pme_desc = "Read requests completed to memory bank 3",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x23,
	},
	{
		.pme_name = "MC_stalls_0",
		.pme_desc = "Clock cycles that requests were stalled in the MCU queues because bank 0 was busy with a previous request",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x24,
	},
	{
		.pme_name = "MC_stalls_2",
		.pme_desc = "Clock cycles that requests were stalled in the MCU queues because bank 2 was busy with a previous request",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x25,
	},

	/* PIC1 memory controller events common to all UltraSPARC-III/III+ processors */
	{
		.pme_name = "MC_writes_0",
		.pme_desc = "Write requests completed to memory bank 0",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x20,
	},
	{
		.pme_name = "MC_writes_1",
		.pme_desc = "Write requests completed to memory bank 1",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x21,
	},
	{
		.pme_name = "MC_writes_2",
		.pme_desc = "Write requests completed to memory bank 2",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x22,
	},
	{
		.pme_name = "MC_writes_3",
		.pme_desc = "Write requests completed to memory bank 3",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x23,
	},
	{
		.pme_name = "MC_stalls_1",
		.pme_desc = "Clock cycles that requests were stalled in the MCU queues because bank 1 was busy with a previous request",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x24,
	},
	{
		.pme_name = "MC_stalls_3",
		.pme_desc = "Clock cycles that requests were stalled in the MCU queues because bank 3 was busy with a previous request",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x25,
	},

	/* PIC0 events specific to UltraSPARC-III+ processors */
	{
		.pme_name = "EC_wb_remote",
		.pme_desc = "Counts the retry event when any victimization for which the processor generates an R_WB transaction to non_LPA address region",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x19,
	},
	{
		.pme_name = "EC_miss_local",
		.pme_desc = "Counts any transaction to an LPA for which the processor issues an RTS/RTO/RS transaction",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x1a,
	},
	{
		.pme_name = "EC_miss_mtag_remote",
		.pme_desc = "Counts any transaction to an LPA in which the processor is required to generate a retry transaction",
		.pme_ctrl = PME_CTRL_S0,
		.pme_val = 0x1b,
	},

	/* PIC1 events specific to UltraSPARC-III+/IIIi processors */
	{
		.pme_name = "Re_DC_missovhd",
		.pme_desc = "Used to measure D-cache stall counts seperatedly for L2-cache hits and misses.  This counter is used with the recirculation and cache access events to seperately calculate the D-cache loads that hit and miss the L2-cache",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x4,
	},

	/* PIC1 events specific to UltraSPARC-III+ processors */
	{
		.pme_name = "EC_miss_mtag_remote",
		.pme_desc = "Counts any transaction to an LPA in which the processor is required to generate a retry transaction",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x28,
	},
	{
		.pme_name = "EC_miss_remote",
		.pme_desc = "Counts the events triggered whenever the processor generates a remote (R_*) transaction and the address is to a non-LPA portion (remote) of the physical address space, or an R_WS transaction due to block-store/block-store-commit to any address space (LPA or non-LPA), or an R-RTO due to store/swap request on Os state to LPA space",
		.pme_ctrl = PME_CTRL_S1,
		.pme_val = 0x29,
	},
};
#define PME_ULTRA3PLUS_EVENT_COUNT	   (sizeof(ultra3plus_pe)/sizeof(pme_sparc_entry_t))
