#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

/*Licence for geline and getdelim*/
/*	$NetBSD: fgetln.c,v 1.9 2008/04/29 06:53:03 martin Exp $	*/

/*-
 * Copyright (c) 2011 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Christos Zoulas.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
ssize_t getdelim(char **buf, size_t *bufsiz, int delimiter, FILE *fp)
{
	char *ptr, *eptr;


	if (*buf == NULL || *bufsiz == 0) {
		*bufsiz = BUFSIZ;
		if ((*buf = malloc(*bufsiz)) == NULL)
			return -1;
	}

	for (ptr = *buf, eptr = *buf + *bufsiz;;) {
		int c = fgetc(fp);
		if (c == -1) {
			if (feof(fp))
				return ptr == *buf ? -1 : ptr - *buf;
			else
				return -1;
		}
		*ptr++ = c;
		if (c == delimiter) {
			*ptr = '\0';
			return ptr - *buf;
		}
		if (ptr + 2 >= eptr) {
			char *nbuf;
			size_t nbufsiz = *bufsiz * 2;
			ssize_t d = ptr - *buf;
			if ((nbuf = realloc(*buf, nbufsiz)) == NULL)
				return -1;
			*buf = nbuf;
			*bufsiz = nbufsiz;
			eptr = nbuf + nbufsiz;
			ptr = nbuf + d;
		}
	}
}

ssize_t
getline(char **buf, size_t *bufsiz, FILE *fp)
{
	return getdelim(buf, bufsiz, '\n', fp);
}

int main ( int argc, char *argv[] )
{
	char filename[512];
	char filename_out[512];
    char chr[256];
    char chr_dir[2000];
    char name[2000];
    char qual[256];
    char strand[256];
    char lengths[200000];
    char offsets[200000];
    char buf[500000];
	printf("%d\n",argc);
	if (argc>=3)
	{
		printf("%s\n",argv[1]);
		strcpy(filename,argv[1]);
		strcpy(filename_out,argv[1]);
		printf("%s\n",argv[2]);
		strcpy(chr_dir,argv[2]);
		strcat(filename_out,".dna");
		FILE *fp = fopen (filename, "r");
		FILE *fop = fopen (filename_out, "w");
		char * line = NULL;
		size_t len = 0;
		ssize_t read;
		while ((read = getline(&line, &len, fp)) != -1) 
		{
			int i=0;
			int j=0;
			for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { chr[j]=line[i]; }
			chr[j]='\0';
			if (line[i]!='\0')
			{
				i++;
				int start=atoi(line+i);
				for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { ; }
				if (line[i]!='\0')
				{
					i++;
					for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { ; }
					if (line[i]!='\0')
					{
						i++;
						for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { name[j]=line[i]; }
						name[j]='\0';
						if (line[i]!='\0')
						{
							i++;
							for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { qual[j]=line[i]; }
							qual[j]='\0';
							if (line[i]!='\0')
							{
								i++;
								for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { strand[j]=line[i]; }
								strand[j]='\0';
								if (line[i]!='\0')
								{
									i++;
									for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { ; }
									if (line[i]!='\0')
									{
										i++;
										for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { ; }
										if (line[i]!='\0')
										{
											i++;
											for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { ; }
											if (line[i]!='\0')
											{
												i++;
												for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { ; }
												if (line[i]!='\0')
												{
													i++;
													for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { lengths[j]=line[i]; }
													lengths[j]='\0';
													if (line[i]!='\0')
													{
														i++;
														for(j=0;line[i]!='\n' && line[i]!='\r' && line[i]!='\t' && line[i]!='\0';i++,j++) { offsets[j]=line[i]; }
														offsets[j]='\0';
														if (line[i]!='\0')
														{
															i++;
															fprintf(fop,"%s",line);
															fprintf(fop,">%s (MAP:%s:%d%s %s %s)\n",name,chr,start,strand,lengths,offsets);
															int k=0;
															int l=0;
															int m=0;
															char filename_chr[256];
															int padding=600;
															strcpy(filename_chr,chr_dir);
															strcat(filename_chr,"/");
															strcat(filename_chr,chr);
															strcat(filename_chr,".fa.cmp1");
															FILE *fp_chr = fopen(filename_chr, "r");
															if (fp_chr!=NULL)
															{
																buf[0]='\0';
																fseek (fp_chr, start-padding, SEEK_SET);
																fgets(buf, padding+1, fp_chr);
																if (buf!=NULL)
																{
																	fprintf(fop,"%s\t-1\t%s\t%d\t%d\t%s\t0\t%s\n",name,chr,start-padding,padding,strand,buf);
																}
																int start_=0;
																int length=0;
																for(k=0,l=0,m=0;offsets[l]!='\0';k++)
																{
																	if (isdigit(offsets[l]))
																	{
																		start_=start+atoi(offsets+l);
																		if (isdigit(lengths[m]))
																		{
																			length=atoi(lengths+m);
																			buf[0]='\0';
																			fseek (fp_chr, start_, SEEK_SET);
																			if (length<500000)
																			{
																				fgets(buf, length+1, fp_chr);
																				if (buf!=NULL)
																				{
																					fprintf(fop,"%s\t%d\t%s\t%d\t%d\t%s\t%s\t%s\n",name,k,chr,start_,length,strand,qual,buf);
																				}
																			} else { fprintf(fop,"%s\t%d\t%s\t%d\t%d\t%s\t%s\tError Reading Sequence\n",name,k,chr,start_,length,strand,qual); }
																		}
																	}
																	for(;offsets[l]!=',' && offsets[l]!='\0';l++) { ; }
																	if (offsets[l]==',') { l++; }
																	for(;lengths[m]!=',' && lengths[m]!='\0';m++) { ; }
																	if (lengths[m]==',') { m++; }
																}
																buf[0]='\0';
																fseek (fp_chr, start_+length, SEEK_SET);
																fgets(buf, padding+1, fp_chr);
																if (buf!=NULL)
																{
																	fprintf(fop,"%s\t+1\t%s\t%d\t%d\t%s\t0\t%s\n",name,chr,start_+length,padding,strand,buf);
																}
																fclose(fp_chr);
															} else { printf("Error opening: %s\n",filename_chr); }
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
    return 0;
}