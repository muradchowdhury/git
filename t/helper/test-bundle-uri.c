#include "test-tool.h"
#include "parse-options.h"
#include "bundle-uri.h"
#include "strbuf.h"
#include "string-list.h"

enum input_mode {
	KEY_VALUE_PAIRS,
	CONFIG_FILE,
};

static int cmd__bundle_uri_parse(int argc, const char **argv, enum input_mode mode)
{
	const char *key_value_usage[] = {
		"test-tool bundle-uri parse-key-values <in",
		NULL
	};
	const char *config_usage[] = {
		"test-tool bundle-uri parse-config <input>",
		NULL
	};
	struct option options[] = {
		OPT_END(),
	};
	const char **usage = key_value_usage;
	struct strbuf sb = STRBUF_INIT;
	struct bundle_list list;
	int err = 0;

	if (mode == CONFIG_FILE)
		usage = config_usage;

	argc = parse_options(argc, argv, NULL, options, usage,
			     PARSE_OPT_STOP_AT_NON_OPTION);

	init_bundle_list(&list);

	switch (mode) {
	case KEY_VALUE_PAIRS:
		if (argc)
			goto usage;
		while (strbuf_getline(&sb, stdin) != EOF) {
			if (bundle_uri_parse_line(&list, sb.buf) < 0)
				err = error("bad line: '%s'", sb.buf);
		}
		break;

	case CONFIG_FILE:
		if (argc != 1)
			goto usage;
		err = parse_bundle_list_in_config_format("<uri>", argv[0], &list);
		break;
	}
	strbuf_release(&sb);

	print_bundle_list(stdout, &list);

	clear_bundle_list(&list);

	return !!err;

usage:
	usage_with_options(usage, options);
}

int cmd__bundle_uri(int argc, const char **argv)
{
	const char *usage[] = {
		"test-tool bundle-uri <subcommand> [<options>]",
		NULL
	};
	struct option options[] = {
		OPT_END(),
	};

	argc = parse_options(argc, argv, NULL, options, usage,
			     PARSE_OPT_STOP_AT_NON_OPTION |
			     PARSE_OPT_KEEP_ARGV0);
	if (argc == 1)
		goto usage;

	if (!strcmp(argv[1], "parse-key-values"))
		return cmd__bundle_uri_parse(argc - 1, argv + 1, KEY_VALUE_PAIRS);
	if (!strcmp(argv[1], "parse-config"))
		return cmd__bundle_uri_parse(argc - 1, argv + 1, CONFIG_FILE);
	error("there is no test-tool bundle-uri tool '%s'", argv[1]);

usage:
	usage_with_options(usage, options);
}