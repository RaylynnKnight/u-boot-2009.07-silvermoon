#ifndef __MACH_NAND_SUPPORTED_H__
#define	__MACH_NAND_SUPPORTED_H__

static struct pxa3xx_nand_cmdset smallpage_cmdset = {
	.read1          = 0x0000,
	.read2          = 0x0050,
	.program        = 0x1080,
	.read_status    = 0x0070,
	.read_id        = 0x0090,
	.erase          = 0xD060,
	.reset          = 0x00FF,
	.lock           = 0x002A,
	.unlock         = 0x2423,
	.lock_status    = 0x007A,
};

static struct pxa3xx_nand_cmdset largepage_cmdset = {
	.read1          = 0x3000,
	.read2          = 0x0050,
	.program        = 0x1080,
	.read_status    = 0x0070,
	.read_id        = 0x0090,
	.erase          = 0xD060,
	.reset          = 0x00FF,
	.lock           = 0x002A,
	.unlock         = 0x2423,
	.lock_status    = 0x007A,
};

static struct pxa3xx_nand_timing common_timing = {
	.tCH	= 40,
	.tCS	= 80,
	.tWH	= 60,
	.tWP	= 100,
	.tRH	= 80,
	.tRP	= 100,
	.tR	= 60000,
	.tWHR	= 400,
	.tAR	= 40,
};

static struct pxa3xx_nand_timing samsung512MbX16_timing = {
	.tCH	= 10,
	.tCS	= 0,
	.tWH	= 20,
	.tWP	= 40,
	.tRH	= 30,
	.tRP	= 40,
	.tR	= 11123,
	.tWHR	= 110,
	.tAR	= 10,
};

static struct pxa3xx_nand_timing samsung2GbX8_timing = {
	.tCH = 10,
	.tCS = 35,
	.tWH = 15,
	.tWP = 25,
	.tRH = 20,
	.tRP = 25,
	.tR = 25000,
	.tWHR = 60,
	.tAR = 10,
};

static struct pxa3xx_nand_timing samsung8GbX8_timing = {
	.tCH = 10,
	.tCS = 35,
	.tWH = 15,
	.tWP = 25,
	.tRH = 20,
	.tRP = 25,
	.tR = 25000,
	.tWHR = 60,
	.tAR = 10,
};

#if defined(CHUMBY_CONFIG_platform)
// Added for HY27UF082G2A-TP 2gbit NAND - being phased out from Silvermoon in favor of eSD
static struct pxa3xx_nand_timing hynix2GbX8_timing = {
	.tCH = 10,
	.tCS = 25,
	.tWH = 20,
	.tWP = 30,
	.tRH = 30,
	.tRP = 30,
	.tR = 25000,
	.tWHR = 110,
	.tAR = 2,
};
#endif

static struct pxa3xx_nand_timing samsung32GbX8_timing = {
	.tCH = 5,
	.tCS = 20,
	.tWH = 10,
	.tWP = 12,
	.tRH = 15,
	.tRP = 12,
	.tR = 25000,
	.tWHR = 60,
	.tAR = 10,
};

static struct pxa3xx_nand_timing micron_timing = {
	.tCH	= 10,
	.tCS	= 25,
	.tWH	= 15,
	.tWP	= 25,
	.tRH	= 15,
	.tRP	= 25,
	.tR	= 25000,
	.tWHR	= 60,
	.tAR	= 10,
};

static struct pxa3xx_nand_timing stm2GbX16_timing = {
	.tCH = 10,
	.tCS = 35,
	.tWH = 15,
	.tWP = 25,
	.tRH = 15,
	.tRP = 25,
	.tR = 25000,
	.tWHR = 60,
	.tAR = 10,
};

struct pxa3xx_nand_flash nand_common = {
	.timing		= &common_timing,
	.cmdset         = &largepage_cmdset,
	.page_per_block	= 64,
	.page_size	= 2048,
	.flash_width	= 8,
	.dfc_width	= 8,
	.ecc_type	= ECC_HAMMIN,
};

static struct pxa3xx_nand_flash samsung512MbX16 = {
	.timing		= &samsung512MbX16_timing,
	.cmdset		= &smallpage_cmdset,
	.name		= "Samsung 512Mibx16",
	.page_per_block	= 32,
	.page_size	= 512,
	.flash_width	= 16,
	.dfc_width	= 16,
	.num_blocks	= 4096,
	.chip_id	= 0x46ec,
	.ecc_type	= ECC_HAMMIN,
};

static struct pxa3xx_nand_flash samsung2GbX8 = {
	.timing		= &samsung2GbX8_timing,
	.cmdset         = &largepage_cmdset,
	.name		= "Samsung 2Gibx8",
	.page_per_block	= 64,
	.page_size	= 2048,
	.flash_width	= 8,
	.dfc_width	= 8,
	.num_blocks	= 2048,
	.chip_id	= 0xdaec,
	.ecc_type	= ECC_HAMMIN,
};

static struct pxa3xx_nand_flash samsung8GbX8 = {
	.timing		= &samsung8GbX8_timing,
	.cmdset         = &largepage_cmdset,
	.name		= "Samsung 8Gibx8",
	.page_per_block	= 128,
	.page_size	= 2048,
	.flash_width	= 8,
	.dfc_width	= 8,
	.num_blocks	= 4096,
	.chip_id	= 0xd3ec,
	.ecc_type	= ECC_BCH,
};

#if defined(CHUMBY_CONFIG_platform)
// Was defined in drivers/mtd/nand/pxa3xx_nand.c as follows:
#if 0
	.enable_arbiter = 1,	/* Data flash bus arbiter enable */
	.page_per_block = 64,	/* Pages per block */
	.row_addr_start = 1,	/* Second cycle start, Row address start position */
         .read_id_bytes = 5,     /* 2 bytes, returned ID bytes */
	.dfc_mode = 0,		/* NAND mode */
	.ncsx = 0,
	.page_size = 2048,	/* Page size in bytes */
	.oob_size = 64,		/* OOB size in bytes */
	.flash_width = 8,	/* Width of Flash memory */
	.dfc_width = 8,		/* Width of flash controller */
	.num_blocks = 2048,	/* Number of physical blocks in Flash */
         .chip_id =  0xdaad,     // 0xaaec, 0xd8ec

	.read_prog_cycles = 5,	/* Read, Program Cycles */
#ifdef CONFIG_MTD_NAND_PXA3xx_UNLOCK
	.unlock_block_cycles = 0,	/* Unlock Block address cycles */
#endif

#endif
static struct pxa3xx_nand_flash hynix2GbX8 = {
	.timing		= &hynix2GbX8_timing,
	.cmdset		= &largepage_cmdset,
	.name		= "Hynix 2Gibx8",
	.page_per_block = 64,
	.page_size	= 2048,
	.flash_width = 8,
	.dfc_width	= 8,
	.num_blocks = 2048,
	.chip_id	= 0xdaad,
	.ecc_type	= ECC_HAMMIN, /// ??? pure speculation, but this is temporary
};
#endif

static struct pxa3xx_nand_flash samsung32GbX8 = {
	.timing		= &common_timing,
	.cmdset         = &largepage_cmdset,
	.name		= "Samsung 32Gibx8",
	.page_per_block	= 128,
	.page_size	= 4096,
	.flash_width	= 8,
	.dfc_width	= 8,
	.num_blocks	= 8192,
	.chip_id	= 0xd7ec,
	.ecc_type	= ECC_BCH,
};

static struct pxa3xx_nand_flash micron1GbX8 = {
	.timing		= &micron_timing,
	.cmdset         = &largepage_cmdset,
	.name		= "Micron 1Gibx8",
	.page_per_block	= 64,
	.page_size	= 2048,
	.flash_width	= 8,
	.dfc_width	= 8,
	.num_blocks	= 1024,
	.chip_id	= 0xa12c,
	.ecc_type	= ECC_HAMMIN,
};

static struct pxa3xx_nand_flash micron1GbX16 = {
	.timing		= &micron_timing,
	.cmdset         = &largepage_cmdset,
	.name		= "Micron 1Gibx16",
	.page_per_block	= 64,
	.page_size	= 2048,
	.flash_width	= 16,
	.dfc_width	= 16,
	.num_blocks	= 1024,
	.chip_id	= 0xb12c,
	.ecc_type	= ECC_HAMMIN,
};

static struct pxa3xx_nand_flash micron2GbX16 = {
	.timing		= &micron_timing,
	.cmdset         = &largepage_cmdset,
	.name		= "Micron 2Gibx16",
	.page_per_block	= 64,
	.page_size	= 2048,
	.flash_width	= 16,
	.dfc_width	= 16,
	.num_blocks	= 2048,
	.chip_id	= 0xbaec,
	.ecc_type	= ECC_HAMMIN,
};

static struct pxa3xx_nand_flash micron4GbX8 = {
	.timing		= &micron_timing,
	.cmdset         = &largepage_cmdset,
	.name		= "Micron 4Gibx8",
	.page_per_block	= 64,
	.page_size	= 2048,
	.flash_width	= 8,
	.dfc_width	= 8,
	.num_blocks	= 4096,
	.chip_id	= 0xdc2c,
	.ecc_type	= ECC_HAMMIN,
};

static struct pxa3xx_nand_flash stm2GbX16 = {
	.timing 	= &stm2GbX16_timing,
	.cmdset         = &largepage_cmdset,
	.name		= "Stm 2Gibx16",
	.page_per_block = 64,
	.page_size 	= 2048,
	.flash_width 	= 16,
	.dfc_width 	= 16,
	.num_blocks 	= 2048,
	.chip_id 	= 0xba20,
	.ecc_type	= ECC_HAMMIN,
};

static struct pxa3xx_nand_flash *builtin_flash_types[] = {
	&nand_common,
#if defined(CHUMBY_CONFIG_platform)
	&hynix2GbX8,
#endif
	&samsung512MbX16,
	&samsung2GbX8,
	&samsung8GbX8,
	&samsung32GbX8,
	&micron1GbX8,
	&micron4GbX8,
	&micron1GbX16,
	&micron2GbX16,
	&stm2GbX16,
};

#endif
