#include "object-store.h"
#include "help.h"
static const char *color_diff_slots[] = {
	[DIFF_CONTEXT]		      = "context",
	[DIFF_METAINFO]		      = "meta",
	[DIFF_FRAGINFO]		      = "frag",
	[DIFF_FILE_OLD]		      = "old",
	[DIFF_FILE_NEW]		      = "new",
	[DIFF_COMMIT]		      = "commit",
	[DIFF_WHITESPACE]	      = "whitespace",
	[DIFF_FUNCINFO]		      = "func",
	[DIFF_FILE_OLD_MOVED]	      = "oldMoved",
	[DIFF_FILE_OLD_MOVED_ALT]     = "oldMovedAlternative",
	[DIFF_FILE_OLD_MOVED_DIM]     = "oldMovedDimmed",
	[DIFF_FILE_OLD_MOVED_ALT_DIM] = "oldMovedAlternativeDimmed",
	[DIFF_FILE_NEW_MOVED]	      = "newMoved",
	[DIFF_FILE_NEW_MOVED_ALT]     = "newMovedAlternative",
	[DIFF_FILE_NEW_MOVED_DIM]     = "newMovedDimmed",
	[DIFF_FILE_NEW_MOVED_ALT_DIM] = "newMovedAlternativeDimmed",
};

define_list_config_array_extra(color_diff_slots, {"plain"});

	if (!strcasecmp(var, "plain"))
	return LOOKUP_CONFIG(color_diff_slots, var);
			options->flags.dirstat_by_line = 0;
			options->flags.dirstat_by_file = 0;
			options->flags.dirstat_by_line = 1;
			options->flags.dirstat_by_file = 0;
			options->flags.dirstat_by_line = 0;
			options->flags.dirstat_by_file = 1;
			options->flags.dirstat_cumulative = 0;
			options->flags.dirstat_cumulative = 1;
int git_config_rename(const char *var, const char *value)
	diff_detect_rename_default = DIFF_DETECT_RENAME;
		BUG("unknown diff symbol");
	BUG("diff is failing to clean up its tempfiles");
	if (diff_mnemonic_prefix && o->flags.reverse_diff) {
	struct diff_words_style_elem new_word, old_word, ctx;
				&style->old_word, style->newline,
				&style->new_word, style->newline,
			&style->old_word, style->newline,
		st->old_word.color = diff_get_color_opt(o, DIFF_FILE_OLD);
		st->new_word.color = diff_get_color_opt(o, DIFF_FILE_NEW);
static void pprint_rename(struct strbuf *name, const char *a, const char *b)
	const char *old_name = a;
	const char *new_name = b;
		quote_c_style(a, name, NULL, 0);
		strbuf_addstr(name, " => ");
		quote_c_style(b, name, NULL, 0);
		return;
	while (*old_name && *new_name && *old_name == *new_name) {
		if (*old_name == '/')
			pfx_length = old_name - a + 1;
		old_name++;
		new_name++;
	old_name = a + len_a;
	new_name = b + len_b;
	while (a + pfx_length - pfx_adjust_for_slash <= old_name &&
	       b + pfx_length - pfx_adjust_for_slash <= new_name &&
	       *old_name == *new_name) {
		if (*old_name == '/')
			sfx_length = len_a - (old_name - a);
		old_name--;
		new_name--;
	strbuf_grow(name, pfx_length + a_midlen + b_midlen + sfx_length + 7);
		strbuf_add(name, a, pfx_length);
		strbuf_addch(name, '{');
	strbuf_add(name, a + pfx_length, a_midlen);
	strbuf_addstr(name, " => ");
	strbuf_add(name, b + pfx_length, b_midlen);
		strbuf_addch(name, '}');
		strbuf_add(name, a + len_a - sfx_length, sfx_length);
		const char *comments;
	struct strbuf pname = STRBUF_INIT;
	if (file->is_renamed)
		pprint_rename(&pname, file->from_name, file->name);
	else
		quote_c_style(file->name, &pname, NULL, 0);

	if (file->comments)
		strbuf_addf(&pname, " (%s)", file->comments);

	file->print_name = strbuf_detach(&pname, NULL);
	unsigned long sum_changes = 0;
		unsigned long changes;
			changes = gather_dirstat(opt, dir, changed, f->name, newbaselen);
			changes = f->changed;
		sum_changes += changes;
		if (sum_changes) {
			int permille = sum_changes * 1000 / changed;
	return sum_changes;
	dir.cumulative = options->flags.dirstat_cumulative;
		if (options->flags.dirstat_by_file) {
	dir.cumulative = options->flags.dirstat_cumulative;
		free(f->print_name);
	if (o->flags.reverse_diff) {
	if (o->flags.allow_textconv) {
	} else if (!o->flags.text &&
		    !o->flags.binary) {
		if (o->flags.binary)
		xpp.anchors = o->anchors;
		xpp.anchors_nr = o->anchors_nr;
		if (o->flags.funccontext)
static char *get_compact_summary(const struct diff_filepair *p, int is_renamed)
{
	if (!is_renamed) {
		if (p->status == DIFF_STATUS_ADDED) {
			if (S_ISLNK(p->two->mode))
				return "new +l";
			else if ((p->two->mode & 0777) == 0755)
				return "new +x";
			else
				return "new";
		} else if (p->status == DIFF_STATUS_DELETED)
			return "gone";
	}
	if (S_ISLNK(p->one->mode) && !S_ISLNK(p->two->mode))
		return "mode -l";
	else if (!S_ISLNK(p->one->mode) && S_ISLNK(p->two->mode))
		return "mode +l";
	else if ((p->one->mode & 0777) == 0644 &&
		 (p->two->mode & 0777) == 0755)
		return "mode +x";
	else if ((p->one->mode & 0777) == 0755 &&
		 (p->two->mode & 0777) == 0644)
		return "mode -x";
	return NULL;
}

	if (o->flags.stat_with_summary)
		data->comments = get_compact_summary(p, data->is_renamed);
		xpp.anchors = o->anchors;
		xpp.anchors_nr = o->anchors_nr;
		o->flags.check_failed = 1;
	if (!FAST_WORKING_DIRECTORY && !want_file && has_object_pack(oid))
	int conv_flags = global_conv_flags_eol;
	if (conv_flags & CONV_EOL_RNDTRP_DIE)
		conv_flags = CONV_EOL_RNDTRP_WARN;
		if (convert_to_git(&the_index, s->path, s->data, s->size, &buf, conv_flags)) {
			type = oid_object_info(the_repository, &s->oid,
					       &s->size);
		s->data = read_object_file(&s->oid, &type, &s->size);
	struct strbuf tempfile = STRBUF_INIT;
	strbuf_addstr(&tempfile, "XXXXXX_");
	strbuf_addstr(&tempfile, base);
	temp->tempfile = mks_tempfile_ts(tempfile.buf, strlen(base) + 1);
	strbuf_release(&tempfile);
		return find_unique_abbrev(oid, abbrev);
			BUG("oid abbreviation out of range: %d", abbrev);
		const unsigned hexsz = the_hash_algo->hexsz;
		int abbrev = o->flags.full_index ? hexsz : DEFAULT_ABBREV;
		if (o->flags.binary) {
				abbrev = hexsz;
	if (o->flags.allow_external) {
	if (!o->flags.allow_external)
	options->flags.rename_empty = 1;
	options->objfind = NULL;
	unsigned check_mask = DIFF_FORMAT_NAME |
			      DIFF_FORMAT_NAME_STATUS |
			      DIFF_FORMAT_CHECKDIFF |
			      DIFF_FORMAT_NO_OUTPUT;
	/*
	 * This must be signed because we're comparing against a potentially
	 * negative value.
	 */
	const int hexsz = the_hash_algo->hexsz;
	if (HAS_MULTI_BITS(options->output_format & check_mask))
	if (HAS_MULTI_BITS(options->pickaxe_opts & DIFF_PICKAXE_KINDS_MASK))
		die(_("-G, -S and --find-object are mutually exclusive"));

	if ((options->xdl_opts & XDF_WHITESPACE_FLAGS))
		options->flags.diff_from_contents = 1;
		options->flags.diff_from_contents = 0;
	if (options->flags.find_copies_harder)
	if (!options->flags.relative_name)
		options->flags.recursive = 1;
	if (options->pickaxe_opts & DIFF_PICKAXE_KINDS_MASK)
		options->flags.recursive = 1;
		options->flags.dirty_submodules = 1;
	if (hexsz < options->abbrev)
		options->abbrev = hexsz; /* full */
	if (options->flags.quick) {
		options->flags.exit_with_status = 1;
	if (options->flags.follow_renames && options->pathspec.nr != 1)
		BUG("stat option does not begin with --stat: %s", arg);
static int parse_objfind_opt(struct diff_options *opt, const char *arg)
{
	struct object_id oid;

	if (get_oid(arg, &oid))
		return error("unable to resolve '%s'", arg);

	if (!opt->objfind)
		opt->objfind = xcalloc(1, sizeof(*opt->objfind));

	opt->pickaxe_opts |= DIFF_PICKAXE_KIND_OBJFIND;
	opt->flags.recursive = 1;
	opt->flags.tree_in_recursive = 1;
	oidset_insert(opt->objfind, &oid);
	return 1;
}

	else if (skip_prefix(arg, "-X", &arg) ||
		 skip_to_optional_arg(arg, "--dirstat", &arg))
	else if (skip_to_optional_arg(arg, "--dirstat-by-file", &arg)) {
	else if (!strcmp(arg, "--compact-summary")) {
		 options->flags.stat_with_summary = 1;
		 options->output_format |= DIFF_FORMAT_DIFFSTAT;
	} else if (!strcmp(arg, "--no-compact-summary"))
		 options->flags.stat_with_summary = 0;
	else if (starts_with(arg, "-B") ||
		 skip_to_optional_arg(arg, "--break-rewrites", NULL)) {
	else if (starts_with(arg, "-M") ||
		 skip_to_optional_arg(arg, "--find-renames", NULL)) {
	else if (starts_with(arg, "-C") ||
		 skip_to_optional_arg(arg, "--find-copies", NULL)) {
			options->flags.find_copies_harder = 1;
		options->flags.rename_empty = 1;
		options->flags.rename_empty = 0;
	else if (skip_to_optional_arg_default(arg, "--relative", &arg, NULL)) {
		options->flags.relative_name = 1;
		if (arg)
			options->prefix = arg;
	else if (!strcmp(arg, "--ignore-cr-at-eol"))
		DIFF_XDL_SET(options, IGNORE_CR_AT_EOL);
	else if (!strcmp(arg, "--patience")) {
		int i;
		/*
		 * Both --patience and --anchored use PATIENCE_DIFF
		 * internally, so remove any anchors previously
		 * specified.
		 */
		for (i = 0; i < options->anchors_nr; i++)
			free(options->anchors[i]);
		options->anchors_nr = 0;
	} else if (!strcmp(arg, "--histogram"))
	} else if (skip_prefix(arg, "--anchored=", &arg)) {
		options->xdl_opts = DIFF_WITH_ALG(options, PATIENCE_DIFF);
		ALLOC_GROW(options->anchors, options->anchors_nr + 1,
			   options->anchors_alloc);
		options->anchors[options->anchors_nr++] = xstrdup(arg);
		options->flags.binary = 1;
		options->flags.full_index = 1;
		options->flags.text = 1;
		options->flags.reverse_diff = 1;
		options->flags.find_copies_harder = 1;
		options->flags.follow_renames = 1;
		options->flags.follow_renames = 0;
		options->flags.default_follow_renames = 0;
	} else if (skip_to_optional_arg_default(arg, "--color", &arg, "always")) {
	} else if (skip_to_optional_arg_default(arg, "--color-words", &options->word_regex, NULL)) {
		options->flags.exit_with_status = 1;
		options->flags.quick = 1;
		options->flags.allow_external = 1;
		options->flags.allow_external = 0;
	else if (!strcmp(arg, "--textconv")) {
		options->flags.allow_textconv = 1;
		options->flags.textconv_set_via_cmdline = 1;
	} else if (!strcmp(arg, "--no-textconv"))
		options->flags.allow_textconv = 0;
	else if (skip_to_optional_arg_default(arg, "--ignore-submodules", &arg, "all")) {
		options->flags.override_submodule_config = 1;
	} else if (skip_to_optional_arg_default(arg, "--submodule", &arg, "log"))
	} else if (skip_prefix(arg, "--find-object=", &arg))
		return parse_objfind_opt(options, arg);
		else if (the_hash_algo->hexsz < options->abbrev)
			options->abbrev = the_hash_algo->hexsz;
		options->flags.funccontext = 1;
		options->flags.funccontext = 1;
		options->flags.funccontext = 0;
	/* Do we want all 40 hex characters? */
	/* An abbreviated value is fine, possibly followed by an ellipsis. */

	if (!print_sha1_ellipsis())
		return abbrev;

	 * In well-behaved cases, where the abbreviated result is the
	struct strbuf names = STRBUF_INIT;

	pprint_rename(&names, p->one->path, p->two->path);
		    renamecopy, names.buf, similarity_index(p));
	strbuf_release(&names);
	fflush(stdout);
	if (0 < needed)
		BUG("WS rules bit mask overlaps with diff symbol flags");
	if (output_format & DIFF_FORMAT_DIRSTAT && options->flags.dirstat_by_line)
	    options->flags.exit_with_status &&
	    options->flags.diff_from_contents) {
	if (options->flags.diff_from_contents) {
			options->flags.has_changes = 1;
			options->flags.has_changes = 0;
			if (!diffopt->flags.no_index)
	if (options->pickaxe_opts & DIFF_PICKAXE_KINDS_MASK)
	if (diff_queued_diff.nr && !options->flags.diff_from_contents)
		options->flags.has_changes = 1;
		options->flags.has_changes = 0;
	if (!opt->flags.exit_with_status &&
	if (opt->flags.exit_with_status &&
	    opt->flags.has_changes)
	    opt->flags.check_failed)
	return (opt->flags.quick &&
		opt->flags.has_changes);
	struct diff_flags orig_flags = options->flags;
	if (!options->flags.override_submodule_config)
	if (options->flags.ignore_submodules)
	if (options->flags.reverse_diff)
	if (!options->flags.diff_from_contents)
		options->flags.has_changes = 1;
	if (options->flags.reverse_diff) {
	if (options->flags.diff_from_contents)
	if (options->flags.quick && options->skip_stat_unmatch &&
	options->flags.has_changes = 1;
		BUG("fill_textconv called with non-textconv driver");
	if (!opt->flags.exit_with_status &&