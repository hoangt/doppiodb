/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0.  If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright 1997 - July 2008 CWI, August 2008 - 2016 MonetDB B.V.
 */

#ifndef _PRINT_H_
#define _PRINT_H_

#include <mal.h>
#include <mal_instruction.h>
#include <mal_interpreter.h>

typedef struct {
	int up, down;
} bipipe;

typedef FILE *fstream;

#ifdef WIN32
#if !defined(LIBMAL) && !defined(LIBATOMS) && !defined(LIBKERNEL) && !defined(LIBMAL) && !defined(LIBOPTIMIZER) && !defined(LIBSCHEDULER) && !defined(LIBMONETDB5)
#define io_export extern __declspec(dllimport)
#else
#define io_export extern __declspec(dllexport)
#endif
#else
#define io_export extern
#endif

io_export str IOprintBoth(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci, int indx, str hd, str tl, int nobat);
io_export str IOprint_val(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr p);
io_export str IOprint_tables(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr p);
io_export str IOprompt_val(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str IOprintf(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str IOprintfStream(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str IOtableAll(stream *f, Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci, int i, int order, int printhead, int printorder);
io_export str IOotable(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str IOtable(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str IOfotable(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str IOftable(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str IOttable(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str IOtotable(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str IOexport(bit *ret, bat *bid, str *fnme);
io_export str IOdatafile(str *ret, str *fnme);
io_export str IOimport(bat *ret, bat *bid, str *fnme);
io_export str io_stdin(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str io_stdout(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
io_export str io_stderr(Client cntxt, MalBlkPtr mb, MalStkPtr stk, InstrPtr pci);
#endif /* _PRINT_H_ */
