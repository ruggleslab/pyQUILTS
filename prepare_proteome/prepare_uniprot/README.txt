1. You need three files:

	A. The UniProt proteome .bed file. You can find this at ftp://ftp.uniprot.org/pub/databases/uniprot/current_release/knowledgebase/genome_annotation_tracks/
		-Enter UPXXXXXXXXX_XXXX_beds folder, and download UPXXXXXXXXX_XXXX_proteome.bed (human only)

	B. A proteome .fasta file from ftp://ftp.uniprot.org/pub/databases/uniprot/current_release/knowledgebase/reference_proteomes/Eukaryota/
		-Download the file UPXXXXXXXXX_XXXX.fasta.gz, where the UP number matches the one from the .bed file you downloaded in step 1A. Unzip this.

	C. A .tab file of gene/protein information from https://www.uniprot.org/uniprot/.
		-On the left side, filter for your organism and SwissProt or TrEMBL
		-Choose these three columns: Entry, Protein names, Gene names
		-Download as a tab separated file

2. Next, you’ll run the python script:

	python prepare_uniprot.py --bed_file [uniprot bed file name] --input_fasta [uniprot fasta file name] --info_file [tab-separated info file name] --version [‘swiss’,’trembl’, or ‘both’]

This will leave you with the five reference files you need to run QUILTS: proteome.bed, transcriptome.bed, proteome.fasta, proteome-genes.txt, proteome-description.txt

Congratulations, you’ve got your reference proteome ready for QUILTS!

(You may move these files to a folder on your system where you'd like to store the proteome DB.)

python prepare_uniprot.py --bed_file "/Users/sarahkeegan/code/ruggleslab/data/pyquilts-db/downloads/uniprot/UP000000589_10090_proteome.bed" --input_fasta "/Users/sarahkeegan/code/ruggleslab/data/pyquilts-db/downloads/uniprot/UP000000589_10090.fasta" --info_file "/Users/sarahkeegan/code/ruggleslab/data/pyquilts-db/downloads/uniprot/uniprotkb_taxonomy_id_9605_2024_07_13.tsv" --version "both"
