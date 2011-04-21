/*
 * Copyright (c) 2011 Google, Inc
 * Contributed by Stephane Eranian <eranian@gmail.com>
 *
 * Based on:
 * Copyright (c) 2007 Advanced Micro Devices, Inc.
 * Contributed by Robert Richter <robert.richter@amd.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

/*
 * Created from: BIOS and Kernel Developer's Guide (BKDG) For AMD
 * Family 14h Processors, 31116 Rev 3.06 - March 2011
 */

static const amd64_entry_t amd64_fam14h_pe[]={
	{.name = "DISPATCHED_FPU",
	.code  = 0x00,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Number of uops dispatched to FPU execution pipelines",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "PIPE0",
		  .udesc = "Pipe 0 (fadd, imul, mmx) ops",
		  .ucode = 0x01,
		},
		{ .uname = "PIPE1",
		  .udesc = "Pipe 1 (fmul, store, mmx) ops",
		  .ucode = 0x02,
		},
		{ .uname = "ANY",
		  .udesc = "Pipe 1 and Pipe 0 ops",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	},
	},
	{.name = "CYCLES_NO_FPU_OPS_RETIRED",
	.code  = 0x01,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Cycles in which the FPU is Empty",
	},
	{.name = "DISPATCHED_FPU_OPS_FAST_FLAG",
	.code  = 0x02,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Dispatched Fast Flag FPU Operations",
	},
	{.name = "RETIRED_SSE_OPERATIONS",
	.code  = 0x03,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired SSE Operations",
	.ngrp = 1,
	.numasks = 8,
	.umasks  = {
		{ .uname = "SINGLE_ADD_SUB_OPS",
		  .udesc = "Single precision add/subtract ops",
		  .ucode = 0x01,
		},
		{ .uname = "SINGLE_MUL_OPS",
		  .udesc = "Single precision multiply ops",
		  .ucode = 0x02,
		},
		{ .uname = "SINGLE_DIV_OPS",
		  .udesc = "Single precision divide/square root ops",
		  .ucode = 0x04,
		},
		{ .uname = "DOUBLE_ADD_SUB_OPS",
		  .udesc = "Double precision add/subtract ops",
		  .ucode = 0x08,
		},
		{ .uname = "DOUBLE_MUL_OPS",
		  .udesc = "Double precision multiply ops",
		  .ucode = 0x10,
		},
		{ .uname = "DOUBLE_DIV_OPS",
		  .udesc = "Double precision divide/square root ops",
		  .ucode = 0x20,
		},
		{ .uname = "OP_TYPE",
		  .udesc = "Op type: 0=uops. 1=FLOPS",
		  .ucode = 0x40,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x7F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "RETIRED_MOVE_OPS",
	.code  = 0x04,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Move Ops",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "ALL_OTHER_MERGING_MOVE_UOPS",
		  .udesc = "All other merging move uops",
		  .ucode = 0x04,
		},
		{ .uname = "ALL_OTHER_MOVE_UOPS",
		  .udesc = "All other move uops",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0c,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "RETIRED_SERIALIZING_OPS",
	.code  = 0x05,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Serializing Ops",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "SSE_BOTTOM_EXECUTING_UOPS",
		  .udesc = "SSE bottom-executing uops retired",
		  .ucode = 0x01,
		},
		{ .uname = "SSE_BOTTOM_SERIALIZING_UOPS",
		  .udesc = "SSE bottom-serializing uops retired",
		  .ucode = 0x02,
		},
		{ .uname = "X87_BOTTOM_EXECUTING_UOPS",
		  .udesc = "x87 bottom-executing uops retired",
		  .ucode = 0x04,
		},
		{ .uname = "X87_BOTTOM_SERIALIZING_UOPS",
		  .udesc = "x87 bottom-serializing uops retired",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "RETIRED_X87_FPU_OPS",
	.code  = 0x11,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Number of x87 floating points ops that have retired",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "ADD_SUB_OPS",
		  .udesc = "add/substract ops",
		  .ucode = 0x01,
		},
		{ .uname = "MULT_OPS",
		  .udesc = "multiply ops",
		  .ucode = 0x02,
		},
		{ .uname = "DIV_FSQRT_OPS",
		  .udesc = "divide and fqsrt ops",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "SEGMENT_REGISTER_LOADS",
	.code  = 0x20,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Segment Register Loads",
	.ngrp = 1,
	.numasks = 8,
	.umasks  = {
		{ .uname = "ES",
		  .udesc = "ES",
		  .ucode = 0x01,
		},
		{ .uname = "CS",
		  .udesc = "CS",
		  .ucode = 0x02,
		},
		{ .uname = "SS",
		  .udesc = "SS",
		  .ucode = 0x04,
		},
		{ .uname = "DS",
		  .udesc = "DS",
		  .ucode = 0x08,
		},
		{ .uname = "FS",
		  .udesc = "FS",
		  .ucode = 0x10,
		},
		{ .uname = "GS",
		  .udesc = "GS",
		  .ucode = 0x20,
		},
		{ .uname = "HS",
		  .udesc = "HS",
		  .ucode = 0x40,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x7F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "PIPELINE_RESTART_DUE_TO_SELF_MODIFYING_CODE",
	.code  = 0x21,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Pipeline Restart Due to Self-Modifying Code",
	},
	{.name = "PIPELINE_RESTART_DUE_TO_PROBE_HIT",
	.code  = 0x22,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Pipeline Restart Due to Probe Hit",
	},
	{.name = "RSQ_FULL",
	.code  = 0x23,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Number of cycles that the RSQ holds retired stores. This buffer holds the stores waiting to retired as well as requests that missed the data cacge and waiting on a refill",
	},
	{.name = "LOCKED_OPS",
	.code  = 0x24,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Locked Operations",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "EXECUTED",
		  .udesc = "number of locked instructions executed",
		  .ucode = 0x01,
		},
		{ .uname = "BUS_LOCK",
		  .udesc = "number of cycles to acquire bus lock",
		  .ucode = 0x02,
		},
		{ .uname = "UNLOCK_LINE",
		  .udesc = "number of cycles to unlock line (not including cache miss)",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "RETIRED_CLFLUSH_INSTRUCTIONS",
	.code  = 0x26,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired CLFLUSH Instructions",
	},
	{.name = "RETIRED_CPUID_INSTRUCTIONS",
	.code  = 0x27,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired CPUID Instructions",
	},
	{.name = "CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS",
	.code  = 0x2A,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Cancelled Store to Load Forward Operations",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "ADDRESS_MISMATCHES",
		  .udesc = "Address mismatches (starting byte not the same).",
		  .ucode = 0x01,
		},
		{ .uname = "STORE_IS_SMALLER_THAN_LOAD",
		  .udesc = "Store is smaller than load.",
		  .ucode = 0x02,
		},
		{ .uname = "MISALIGNED",
		  .udesc = "Misaligned.",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "DATA_CACHE_ACCESSES",
	.code  = 0x40,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Data Cache Accesses",
	},
	{.name = "DATA_CACHE_MISSES",
	.code  = 0x41,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Data Cache Misses",
	},
	{.name = "DATA_CACHE_REFILLS",
	.code  = 0x42,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Data Cache Refills from L2 or Northbridge",
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "UNCACHEABLE",
		  .udesc = "from non-cacheable data",
		  .ucode = 0x01,
		},
		{ .uname = "SHARED",
		  .udesc = "from shared lines",
		  .ucode = 0x02,
		},
		{ .uname = "EXCLUSIVE",
		  .udesc = "from exclusive lines",
		  .ucode = 0x04,
		},
		{ .uname = "OWNED",
		  .udesc = "from owned lines",
		  .ucode = 0x08,
		},
		{ .uname = "MODIFIED",
		  .udesc = "from modified lines",
		  .ucode = 0x10,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x1F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "DATA_CACHE_REFILLS_FROM_NB",
	.code  = 0x43,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Data Cache Refills from the Northbridge",
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "UNCACHEABLE",
		  .udesc = "uncacheable data",
		  .ucode = 0x01,
		},
		{ .uname = "SHARED",
		  .udesc = "Shared",
		  .ucode = 0x02,
		},
		{ .uname = "EXCLUSIVE",
		  .udesc = "Exclusive",
		  .ucode = 0x04,
		},
		{ .uname = "OWNED",
		  .udesc = "Owned",
		  .ucode = 0x08,
		},
		{ .uname = "MODIFIED",
		  .udesc = "Modified",
		  .ucode = 0x10,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x1F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "DATA_CACHE_LINES_EVICTED",
	.code  = 0x44,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Data Cache Lines Evicted",
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "PROBE",
		  .udesc = "eviction from probe",
		  .ucode = 0x01,
		},
		{ .uname = "SHARED",
		  .udesc = "shared eviction",
		  .ucode = 0x02,
		},
		{ .uname = "EXCLUSIVE",
		  .udesc = "Exclusive eviction",
		  .ucode = 0x04,
		},
		{ .uname = "OWNED",
		  .udesc = "owned eviction",
		  .ucode = 0x08,
		},
		{ .uname = "MODIFIED",
		  .udesc = "modified eviction",
		  .ucode = 0x10,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x1F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "L1_DTLB_MISS_AND_L2_DTLB_HIT",
	.code  = 0x45,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Number of data cache accesses that miss in the L1 DTLB and hit the L2 DTLB. This is a speculative event",
	},
	{.name = "DTLB_MISS",
	.code  = 0x46,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "L1 DTLB and L2 DTLB Miss",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "STORES_L1TLB_MISS",
		  .udesc = "stores that miss L1TLB",
		  .ucode = 0x01,
		},
		{ .uname = "LOADS_L1TLB_MISS",
		  .udesc = "loads that miss L1TLB",
		  .ucode = 0x02,
		},
		{ .uname = "STORES_L2TLB_MISS",
		  .udesc = "stores that miss L2TLB",
		  .ucode = 0x04,
		},
		{ .uname = "LOADS_L2TLB_MISS",
		  .udesc = "loads that miss L2TLB",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "MISALIGNED_ACCESSES",
	.code  = 0x47,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Misaligned Accesses",
	},
	{.name = "PREFETCH_INSTRUCTIONS_DISPATCHED",
	.code  = 0x4B,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Prefetch Instructions Dispatched",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "LOAD",
		  .udesc = "Load (Prefetch, PrefetchT0/T1/T2)",
		  .ucode = 0x01,
		},
		{ .uname = "STORE",
		  .udesc = "Store (PrefetchW)",
		  .ucode = 0x02,
		},
		{ .uname = "NTA",
		  .udesc = "NTA (PrefetchNTA)",
		  .ucode = 0x04,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "DCACHE_MISSES_BY_LOCKED_INSTRUCTIONS",
	.code  = 0x4C,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "DCACHE Misses by Locked Instructions",
	},
	{.name = "L1_DTLB_HIT",
	.code  = 0x4D,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "L1 DTLB Hit",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "L1_4K_TLB_HIT",
		  .udesc = "L1 4K TLB hit",
		  .ucode = 0x01,
		},
		{ .uname = "L1_2M_TLB_HIT",
		  .udesc = "L1 2M TLB hit",
		  .ucode = 0x02,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "DCACHE_SW_PREFETCHES",
	.code  = 0x52,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Number of software prefetches that do not cuase an actual data cache refill",
	.numasks = 5,
	.ngrp = 1,
	.umasks  = {
		{ .uname = "HIT",
		  .udesc = "SW prefetch hit in the data cache",
		  .ucode = 0x01,
		},
		{ .uname = "PENDING_FILL",
		  .udesc = "SW prefetch hit a pending fill",
		  .ucode = 0x02,
		},
		{ .uname = "NO_MAB",
		  .udesc = "SW prefetch does not get a MAB",
		  .ucode = 0x04,
		},
		{ .uname = "L2_HIT",
		  .udesc = "SW prefetch hits L2",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "GLOBAL_TLB_FLUSHES",
	.code  = 0x54,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Global TLB Flushes",
	},
	{.name = "MEMORY_REQUESTS",
	.code  = 0x65,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Memory Requests by Type",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "NON_CACHEABLE",
		  .udesc = "Requests to non-cacheable (UC) memory",
		  .ucode = 0x01,
		},
		{ .uname = "WRITE_COMBINING",
		  .udesc = "Requests to write-combining (WC) memory or WC buffer flushes to WB memory",
		  .ucode = 0x02,
		},
		{ .uname = "STREAMING_STORE",
		  .udesc = "Streaming store (SS) requests",
		  .ucode = 0x80,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x83,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "MAB_REQUESTS",
	.code  = 0x68,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Number of L1 I-cache and D-cache misses per buffer. Average latency by combining with MAB_WAIT_CYCLES.",
	.ngrp = 1,
	.numasks = 12,
	.umasks  = {
		{ .uname = "DC_BUFFER_0",
		  .udesc = "Data cache buffer 0",
		  .ucode = 0x00,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_1",
		  .udesc = "Data cache buffer 1",
		  .ucode = 0x01,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_2",
		  .udesc = "Data cache buffer 2",
		  .ucode = 0x02,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_3",
		  .udesc = "Data cache buffer 3",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_4",
		  .udesc = "Data cache buffer 4",
		  .ucode = 0x04,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_5",
		  .udesc = "Data cache buffer 5",
		  .ucode = 0x05,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_6",
		  .udesc = "Data cache buffer 6",
		  .ucode = 0x06,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_7",
		  .udesc = "Data cache buffer 7",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "IC_BUFFER_0",
		  .udesc = "Instruction cache Buffer 1",
		  .ucode = 0x08,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "IC_BUFFER_1",
		  .udesc = "Instructions cache buffer 1",
		  .ucode = 0x09,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "ANY_IC_BUFFER",
		  .udesc = "any instruction cache buffer",
		  .ucode = 0x0a,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "ANY_DC_BUFFER",
		  .udesc = "any data cache buffer",
		  .ucode = 0x0b,
		  .uflags = AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "MAB_WAIT_CYCLES",
	.code  = 0x69,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Latency of L1 I-cache and D-cache misses per buffer. Average latency by combining with MAB_REQUESTS.",
	.numasks = 12,
	.ngrp = 1,
	.umasks  = {
		{ .uname = "DC_BUFFER_0",
		  .udesc = "Data cache buffer 0",
		  .ucode = 0x00,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_1",
		  .udesc = "Data cache buffer 1",
		  .ucode = 0x01,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_2",
		  .udesc = "Data cache buffer 2",
		  .ucode = 0x02,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_3",
		  .udesc = "Data cache buffer 3",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_4",
		  .udesc = "Data cache buffer 4",
		  .ucode = 0x04,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_5",
		  .udesc = "Data cache buffer 5",
		  .ucode = 0x05,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_6",
		  .udesc = "Data cache buffer 6",
		  .ucode = 0x06,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "DC_BUFFER_7",
		  .udesc = "Data cache buffer 7",
		  .ucode = 0x07,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "IC_BUFFER_0",
		  .udesc = "Instruction cache Buffer 1",
		  .ucode = 0x08,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "IC_BUFFER_1",
		  .udesc = "Instructions cache buffer 1",
		  .ucode = 0x09,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "ANY_IC_BUFFER",
		  .udesc = "any instruction cache buffer",
		  .ucode = 0x0a,
		  .uflags = AMD64_FL_NCOMBO,
		},
		{ .uname = "ANY_DC_BUFFER",
		  .udesc = "any data cache buffer",
		  .ucode = 0x0b,
		  .uflags = AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "SYSTEM_READ_RESPONSES",
	.code  = 0x6C,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Northbridge Read Responses by Coherency State",
	.ngrp = 1,
	.numasks = 8,
	.umasks  = {
		{ .uname = "EXCLUSIVE",
		  .udesc = "Exclusive",
		  .ucode = 0x01,
		},
		{ .uname = "MODIFIED",
		  .udesc = "Modified",
		  .ucode = 0x02,
		},
		{ .uname = "SHARED",
		  .udesc = "Shared",
		  .ucode = 0x04,
		},
		{ .uname = "OWNED",
		  .udesc = "Owned",
		  .ucode = 0x08,
		},
		{ .uname = "DATA_ERROR",
		  .udesc = "Data Error",
		  .ucode = 0x10,
		},
		{ .uname = "DIRTY_SUCCESS",
		  .udesc = "Change-to-dirty success",
		  .ucode = 0x20,
		},
		{ .uname = "UNCACHEABLE",
		  .udesc = "uncacheable",
		  .ucode = 0x40,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x7F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "CPU_CLK_UNHALTED",
	.code  = 0x76,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "CPU Clocks not Halted",
	},
	{.name = "REQUESTS_TO_L2",
	.code  = 0x7D,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Requests to L2 Cache",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "INSTRUCTIONS",
		  .udesc = "IC fill",
		  .ucode = 0x01,
		},
		{ .uname = "DATA",
		  .udesc = "DC fill",
		  .ucode = 0x02,
		},
		{ .uname = "SNOOP",
		  .udesc = "Tag snoop request",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0b,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "L2_CACHE_MISS",
	.code  = 0x7E,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "L2 Cache Misses",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "INSTRUCTIONS",
		  .udesc = "IC fill",
		  .ucode = 0x01,
		},
		{ .uname = "DATA",
		  .udesc = "DC fill (includes possible replays, whereas EventSelect 041h does not)",
		  .ucode = 0x02,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "L2_FILL_WRITEBACK",
	.code  = 0x7F,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "L2 Fill/Writeback",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "L2_FILLS",
		  .udesc = "L2 fills (victims from L1 caches, TLB page table walks and data prefetches)",
		  .ucode = 0x01,
		},
		{ .uname = "L2_WRITEBACKS",
		  .udesc = "L2 Writebacks to system.",
		  .ucode = 0x02,
		},
		{ .uname = "IC_ATTR_WRITES_L2_ACCESS",
		  .udesc = "ic attribute writes which access the L2",
		  .ucode = 0x04,
		},
		{ .uname = "IC_ATTR_WRITES_L2_WRITES",
		  .udesc = "ic attribute writes which store into the L2",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0f,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "INSTRUCTION_CACHE_FETCHES",
	.code  = 0x80,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Instruction Cache Fetches",
	},
	{.name = "INSTRUCTION_CACHE_MISSES",
	.code  = 0x81,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Instruction Cache Misses",
	},
	{.name = "INSTRUCTION_CACHE_REFILLS_FROM_L2",
	.code  = 0x82,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Instruction Cache Refills from L2",
	},
	{.name = "INSTRUCTION_CACHE_REFILLS_FROM_SYSTEM",
	.code  = 0x83,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Instruction Cache Refills from System",
	},
	{.name = "L1_ITLB_MISS_AND_L2_ITLB_MISS",
	.code  = 0x85,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "L1 ITLB Miss and L2 ITLB Miss",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "4K_PAGE_FETCHES",
		  .udesc = "Instruction fetches to a 4K page.",
		  .ucode = 0x01,
		},
		{ .uname = "2M_PAGE_FETCHES",
		  .udesc = "Instruction fetches to a 2M page.",
		  .ucode = 0x02,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "INSTRUCTION_FETCH_STALL",
	.code  = 0x87,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Instruction Fetch Stall",
	},
	{.name = "RETURN_STACK_HITS",
	.code  = 0x88,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Return Stack Hits",
	},
	{.name = "RETURN_STACK_OVERFLOWS",
	.code  = 0x89,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Return Stack Overflows",
	},
	{.name = "INSTRUCTION_CACHE_VICTIMS",
	.code  = 0x8B,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Instruction Cache Victims",
	},
	{.name = "INSTRUCTION_CACHE_LINES_INVALIDATED",
	.code  = 0x8C,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Instruction Cache Lines Invalidated",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "INVALIDATING_LS_PROBE",
		  .udesc = "IC invalidate due to an LS probe",
		  .ucode = 0x01,
		},
		{ .uname = "INVALIDATING_BU_PROBE",
		  .udesc = "IC invalidate due to a BU probe",
		  .ucode = 0x02,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "ITLB_RELOADS",
	.code  = 0x99,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "ITLB Reloads",
	},
	{.name = "ITLB_RELOADS_ABORTED",
	.code  = 0x9A,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "ITLB Reloads Aborted",
	},
	{.name = "RETIRED_INSTRUCTIONS",
	.code  = 0xC0,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Instructions",
	},
	{.name = "RETIRED_UOPS",
	.code  = 0xC1,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired uops",
	},
	{.name = "RETIRED_BRANCH_INSTRUCTIONS",
	.code  = 0xC2,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Branch Instructions",
	},
	{.name = "RETIRED_MISPREDICTED_BRANCH_INSTRUCTIONS",
	.code  = 0xC3,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Mispredicted Branch Instructions",
	},
	{.name = "RETIRED_TAKEN_BRANCH_INSTRUCTIONS",
	.code  = 0xC4,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Taken Branch Instructions",
	},
	{.name = "RETIRED_TAKEN_BRANCH_INSTRUCTIONS_MISPREDICTED",
	.code  = 0xC5,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Taken Branch Instructions Mispredicted",
	},
	{.name = "RETIRED_FAR_CONTROL_TRANSFERS",
	.code  = 0xC6,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Far Control Transfers",
	},
	{.name = "RETIRED_BRANCH_RESYNCS",
	.code  = 0xC7,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Branch Resyncs",
	},
	{.name = "RETIRED_NEAR_RETURNS",
	.code  = 0xC8,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Near Returns",
	},
	{.name = "RETIRED_NEAR_RETURNS_MISPREDICTED",
	.code  = 0xC9,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Near Returns Mispredicted",
	},
	{.name = "RETIRED_INDIRECT_BRANCHES_MISPREDICTED",
	.code  = 0xCA,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired Indirect Branches Mispredicted",
	},
	{.name = "RETIRED_MMX_AND_FP_INSTRUCTIONS",
	.code  = 0xCB,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Retired MMX/FP Instructions",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "X87",
		  .udesc = "x87 instructions",
		  .ucode = 0x01,
		},
		{ .uname = "MMX_AND_3DNOW",
		  .udesc = "MMX and 3DNow! instructions",
		  .ucode = 0x02,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x03,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "INTERRUPTS_MASKED_CYCLES",
	.code  = 0xCD,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Interrupts-Masked Cycles",
	},
	{.name = "INTERRUPTS_MASKED_CYCLES_WITH_INTERRUPT_PENDING",
	.code  = 0xCE,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Interrupts-Masked Cycles with Interrupt Pending",
	},
	{.name = "INTERRUPTS_TAKEN",
	.code  = 0xCF,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Interrupts Taken",
	},
	{.name = "FPU_EXCEPTIONS",
	.code  = 0xDB,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "FPU Exceptions",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "X87_RECLASS_MICROFAULTS",
		  .udesc = "x87 reclass microfaults",
		  .ucode = 0x01,
		},
		{ .uname = "SSE_RETYPE_MICROFAULTS",
		  .udesc = "SSE retype microfaults",
		  .ucode = 0x02,
		},
		{ .uname = "SSE_RECLASS_MICROFAULTS",
		  .udesc = "SSE reclass microfaults",
		  .ucode = 0x04,
		},
		{ .uname = "SSE_AND_X87_MICROTRAPS",
		  .udesc = "SSE and x87 microtraps",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "DR0_BREAKPOINT_MATCHES",
	.code  = 0xDC,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "DR0 Breakpoint Matches",
	},
	{.name = "DR1_BREAKPOINT_MATCHES",
	.code  = 0xDD,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "DR1 Breakpoint Matches",
	},
	{.name = "DR2_BREAKPOINT_MATCHES",
	.code  = 0xDE,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "DR2 Breakpoint Matches",
	},
	{.name = "DR3_BREAKPOINT_MATCHES",
	.code  = 0xDF,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "DR3 Breakpoint Matches",
	},
	{.name = "DRAM_ACCESSES_PAGE",
	.code  = 0xE0,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "DRAM Accesses",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "HIT",
		  .udesc = "DCT0 Page hit",
		  .ucode = 0x01,
		},
		{ .uname = "MISS",
		  .udesc = "DCT0 Page Miss",
		  .ucode = 0x02,
		},
		{ .uname = "CONFLICT",
		  .udesc = "DCT0 Page Conflict",
		  .ucode = 0x04,
		},
		{ .uname = "WRITE_REQUEST",
		  .udesc = "Write request",
		  .ucode = 0x40,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x47,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "MEMORY_CONTROLLER_PAGE_TABLE",
	.code  = 0xE1,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Number of page table events in the local DRAM controller",
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "DCT0_PAGE_TABLE_OVERFLOW",
		  .udesc = "DCT0 Page Table Overflow",
		  .ucode = 0x01,
		},
		{ .uname = "DCT0_PAGE_TABLE_STALE_HIT",
		  .udesc = "DCT0 number of stale table entry hits (hit on a page closed too soon)",
		  .ucode = 0x02,
		},
		{ .uname = "DCT0_PAGE_TABLE_IDLE_INC",
		  .udesc = "DCT0 page table idle cycle limit incremented",
		  .ucode = 0x04,
		},
		{ .uname = "DCT0_PAGE_TABLE_IDLE_DEC",
		  .udesc = "DCT0 page table idle cycle limit decremented",
		  .ucode = 0x08,
		},
		{ .uname = "DCT0_PAGE_TABLE_CLOSED",
		  .udesc = "DCT0 page table is closed due to row inactivity",
		  .ucode = 0x10,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x1f,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "MEMORY_CONTROLLER_SLOT_MISSES",
	.code  = 0xE2,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Memory Controller DRAM Command Slots Missed",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "DCT0_RBD",
		  .udesc = "DCT0 RBD",
		  .ucode = 0x10,
		},
		{ .uname = "DCT0_PREFETCH",
		  .udesc = "DCT0 prefetch",
		  .ucode = 0x40,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x50,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
#if 0
/* See AMD64 Fam14h revision guide:
 * Errata 433: Performance Counters Do Not Accurately Count Memory Turnaround Time */
 */
	{.name = "MEMORY_CONTROLLER_TURNAROUNDS",
	.code  = 0xE3,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Memory Controller Turnarounds",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "DCT0_READ_TO_WRITE",
		  .udesc = "DCT0 read-to-write turnaround",
		  .ucode = 0x01,
		},
		{ .uname = "DCT0_WRITE_TO_READ",
		  .udesc = "DCT0 write-to-read turnaround",
		  .ucode = 0x02,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x3,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
#endif
	{.name = "MEMORY_CONTROLLER_RBD_QUEUE_EVENTS",
	.code  = 0xE4,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Memory Controller Bypass Counter Saturation",
	.ngrp = 1,
	.numasks = 3,
	.umasks  = {
		{ .uname = "DCQ_BYPASS_MAX",
		  .udesc = "DCQ_BYPASS_MAX counter reached",
		  .ucode = 0x04,
		},
		{ .uname = "BANK_CLOSED",
		  .udesc = "bank is closed due to bank conflict with an outstanding request in the RBD queue",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0c,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "THERMAL_STATUS",
	.code  = 0xE8,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Thermal Status",
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "MEMHOT_L",
		  .udesc = "MEMHOT_L assertions",
		  .ucode = 0x01,
		},
		{ .uname = "HTC_TRANSITION",
		  .udesc = "number of times HTC transitions from inactive to active",
		  .ucode = 0x04,
		},
		{ .uname = "CLOCKS_HTC_P_STATE_INACTIVE",
		  .udesc = "Number of clocks HTC P-state is inactive.",
		  .ucode = 0x20,
		},
		{ .uname = "CLOCKS_HTC_P_STATE_ACTIVE",
		  .udesc = "Number of clocks HTC P-state is active",
		  .ucode = 0x40,
		},
		{ .uname = "PROCHOT_L",
		  .udesc = "PROCHOT_L asserted by an external source and the assertion causes a P-state change",
		  .ucode = 0x80,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0xC5,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "CPU_IO_REQUESTS_TO_MEMORY_IO",
	.code  = 0xE9,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "CPU/IO Requests to Memory/IO",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "I_O_TO_I_O",
		  .udesc = "IO to IO",
		  .ucode = 0x01,
		},
		{ .uname = "I_O_TO_MEM",
		  .udesc = "IO to Mem",
		  .ucode = 0x02,
		},
		{ .uname = "CPU_TO_I_O",
		  .udesc = "CPU to IO",
		  .ucode = 0x04,
		},
		{ .uname = "CPU_TO_MEM",
		  .udesc = "CPU to Mem",
		  .ucode = 0x08,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x0F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "CACHE_BLOCK",
	.code  = 0xEA,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Cache Block Commands",
	.ngrp = 1,
	.numasks = 6,
	.umasks  = {
		{ .uname = "VICTIM_WRITEBACK",
		  .udesc = "Victim Block (Writeback)",
		  .ucode = 0x01,
		},
		{ .uname = "DCACHE_LOAD_MISS",
		  .udesc = "Read Block (Dcache load miss refill)",
		  .ucode = 0x04,
		},
		{ .uname = "SHARED_ICACHE_REFILL",
		  .udesc = "Read Block Shared (Icache refill)",
		  .ucode = 0x08,
		},
		{ .uname = "READ_BLOCK_MODIFIED",
		  .udesc = "Read Block Modified (Dcache store miss refill)",
		  .ucode = 0x10,
		},
		{ .uname = "CHANGE_TO_DIRTY",
		  .udesc = "Change-to-Dirty (first store to clean block already in cache)",
		  .ucode = 0x20,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x3D,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "SIZED_COMMANDS",
	.code  = 0xEB,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Sized Commands",
	.ngrp = 1,
	.numasks = 7,
	.umasks  = {
		{ .uname = "NON_POSTED_WRITE_BYTE",
		  .udesc = "Non-Posted SzWr Byte (1-32 bytes) Legacy or mapped IO, typically 1-4 bytes",
		  .ucode = 0x01,
		},
		{ .uname = "NON_POSTED_WRITE_DWORD",
		  .udesc = "Non-Posted SzWr DW (1-16 dwords) Legacy or mapped IO, typically 1 DWORD",
		  .ucode = 0x02,
		},
		{ .uname = "POSTED_WRITE_BYTE",
		  .udesc = "Posted SzWr Byte (1-32 bytes) Subcache-line DMA writes, size varies; also flushes of partially-filled Write Combining buffer",
		  .ucode = 0x04,
		},
		{ .uname = "POSTED_WRITE_DWORD",
		  .udesc = "Posted SzWr DW (1-16 dwords) Block-oriented DMA writes, often cache-line sized; also processor Write Combining buffer flushes",
		  .ucode = 0x08,
		},
		{ .uname = "READ_BYTE_4_BYTES",
		  .udesc = "SzRd Byte (4 bytes) Legacy or mapped IO",
		  .ucode = 0x10,
		},
		{ .uname = "READ_DWORD_1_16_DWORDS",
		  .udesc = "SzRd DW (1-16 dwords) Block-oriented DMA reads, typically cache-line size",
		  .ucode = 0x20,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x3F,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "PROBE",
	.code  = 0xEC,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Probe Responses and Upstream Requests",
	.ngrp = 1,
	.numasks = 8,
	.umasks  = {
		{ .uname = "MISS",
		  .udesc = "Probe miss",
		  .ucode = 0x01,
		},
		{ .uname = "HIT_CLEAN",
		  .udesc = "Probe hit clean",
		  .ucode = 0x02,
		},
		{ .uname = "HIT_DIRTY_NO_MEMORY_CANCEL",
		  .udesc = "Probe hit dirty without memory cancel (probed by Sized Write or Change2Dirty)",
		  .ucode = 0x04,
		},
		{ .uname = "HIT_DIRTY_WITH_MEMORY_CANCEL",
		  .udesc = "Probe hit dirty with memory cancel (probed by DMA read or cache refill request)",
		  .ucode = 0x08,
		},
		{ .uname = "UPSTREAM_HIGH_PRIO_READS",
		  .udesc = "Upstream high priority reads",
		  .ucode = 0x10,
		},
		{ .uname = "UPSTREAM_LOW_PRIO_READS",
		  .udesc = "Upstream low priority reads",
		  .ucode = 0x20,
		},
		{ .uname = "UPSTREAM_LOW_PRIO_WRITES",
		  .udesc = "Upstream non-ISOC writes",
		  .ucode = 0x80,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0xBF,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "DEV_EVENTS",
	.code  = 0xEE,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "DEV Events",
	.ngrp = 1,
	.numasks = 4,
	.umasks  = {
		{ .uname = "HIT",
		  .udesc = "DEV hit",
		  .ucode = 0x10,
		},
		{ .uname = "MISS",
		  .udesc = "DEV miss",
		  .ucode = 0x20,
		},
		{ .uname = "ERROR",
		  .udesc = "DEV error",
		  .ucode = 0x40,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x70,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "MEMORY_CONTROLLER_REQUESTS",
	.code  = 0x1F0,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Memory Controller Requests",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "32_BYTES_WRITES",
		  .udesc = "32 Bytes Sized Writes",
		  .ucode = 0x08,
		},
		{ .uname = "64_BYTES_WRITES",
		  .udesc = "64 Bytes Sized Writes",
		  .ucode = 0x10,
		},
		{ .uname = "32_BYTES_READS",
		  .udesc = "32 Bytes Sized Reads",
		  .ucode = 0x20,
		},
		{ .uname = "64_BYTES_READS",
		  .udesc = "64 Byte Sized Reads",
		  .ucode = 0x40,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x78,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "SIDEBAND_SIGNALS_SPECIAL_SIGNALS",
	.code  = 0x1E9,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Sideband signals and special cycles",
	.ngrp = 1,
	.numasks = 5,
	.umasks  = {
		{ .uname = "STOPGRANT",
		  .udesc = "Stopgrant",
		  .ucode = 0x02,
		},
		{ .uname = "SHUTDOWN",
		  .udesc = "Shutdown",
		  .ucode = 0x04,
		},
		{ .uname = "WBINVD",
		  .udesc = "Wbinvd",
		  .ucode = 0x08,
		},
		{ .uname = "INVD",
		  .udesc = "Invd",
		  .ucode = 0x10,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x1C,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "INTERRUPT_EVENTS",
	.code  = 0x1EA,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "Interrupt events",
	.ngrp = 1,
	.numasks = 9,
	.umasks  = {
		{ .uname = "FIXED_AND_LPA",
		  .udesc = "Fixed and LPA",
		  .ucode = 0x01,
		},
		{ .uname = "LPA",
		  .udesc = "LPA",
		  .ucode = 0x02,
		},
		{ .uname = "SMI",
		  .udesc = "SMI",
		  .ucode = 0x04,
		},
		{ .uname = "NMI",
		  .udesc = "NMI",
		  .ucode = 0x08,
		},
		{ .uname = "INIT",
		  .udesc = "INIT",
		  .ucode = 0x10,
		},
		{ .uname = "STARTUP",
		  .udesc = "STARTUP",
		  .ucode = 0x20,
		},
		{ .uname = "INT",
		  .udesc = "INT",
		  .ucode = 0x40,
		},
		{ .uname = "EOI",
		  .udesc = "EOI",
		  .ucode = 0x80,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0xFF,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
	{.name = "PDC_MISS",
	.code  = 0x162,
	.modmsk = AMD64_FAM14H_ATTRS,
	.desc  = "PDC miss",
	.ngrp = 1,
	.numasks = 7,
	.umasks  = {
		{ .uname = "HOST_PDE_LEVEL",
		  .udesc = "Host PDE level",
		  .ucode = 0x01,
		},
		{ .uname = "HOST_PDPE_LEVEL",
		  .udesc = "Host PDPE level",
		  .ucode = 0x02,
		},
		{ .uname = "HOST_PML4E_LEVEL",
		  .udesc = "Host PML4E level",
		  .ucode = 0x04,
		},
		{ .uname = "GUEST_PDE_LEVEL",
		  .udesc = "Guest PDE level",
		  .ucode = 0x10,
		},
		{ .uname = "GUEST_PDPE_LEVEL",
		  .udesc = "Guest PDPE level",
		  .ucode = 0x20,
		},
		{ .uname = "GUEST_PML4E_LEVEL",
		  .udesc = "Guest PML4E level",
		  .ucode = 0x40,
		},
		{ .uname = "ALL",
		  .udesc = "All sub-events selected",
		  .ucode = 0x67,
		  .uflags = AMD64_FL_DFL|AMD64_FL_NCOMBO,
		},
	 },
	},
};

#define PME_AMD64_FAM14H_EVENT_COUNT		(sizeof(amd64_fam14h_pe)/sizeof(amd64_entry_t))
