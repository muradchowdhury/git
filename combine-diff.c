#include "object-store.h"
				    struct lline *newline, int lennew,
	if (newline == NULL)
		return newline;
		for (j = 1, newend = newline; j < lennew + 1; j++) {
				newline = lline->next;
	newend = newline;
		blob = read_object_file(oid, &type, size);
	int abbrev = opt->flags.full_index ? GIT_SHA1_HEXSZ : DEFAULT_ABBREV;
		abb = find_unique_abbrev(&elem->parent[i].oid,
	abb = find_unique_abbrev(&elem->oid, abbrev);
	if (opt->flags.allow_textconv)
			if (resolve_gitlink_ref(elem->path, "HEAD", &oid) < 0)
				if (convert_to_git(&the_index, elem->path, result, len, &buf, global_conv_flags_eol)) {
	diffopts.flags.recursive = 1;
	diffopts.flags.allow_external = 0;
			opt->flags.follow_renames	||
			(opt->pickaxe_opts & DIFF_PICKAXE_KINDS_MASK)	||