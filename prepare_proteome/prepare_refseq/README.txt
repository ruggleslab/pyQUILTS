You need three files:

1. refLink.txt from http://hgdownload.cse.ucsc.edu/goldenpath/hgFixed/database/refLink.txt.gz

2. refSeq.bed from https://genome.ucsc.edu/cgi-bin/hgTables
-Genome: Human, group: Genes & Gene Predictions, Track: RefSeq Genes (for hg19) or NCBI RefSeq (for hg38), table: refGene,
output format: BED, then on the next page create one BED record per whole gene

3. proteome.fasta from https://genome.ucsc.edu/cgi-bin/hgTables
-Genome: Human, group: Genes & Gene Predictions, Track: RefSeq Genes, table: refGene, output format: sequence,
then on the next page: proteins

3. Run the prepare_refseq.py script:

	python prepare_refseq.py <the file in step 1> <the file in step 2>

This should output 4 files in the same folder as the prepare_ensembl.py script:

    transcriptome.bed, proteome.bed, proteome-genes.txt, proteome-descriptions.txt
    (in addition to the proteome.fasta file you downloaded)

Congratulations, you’ve got your reference proteome ready for QUILTS!

(You may move these files to a folder on your system where you'd like to store the proteome DB.)

