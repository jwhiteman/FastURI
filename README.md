# FastURI:

FastURI (wip) is a a Ragel-based URI parser for Ruby

In my exceedingly unscientific explorations thus far, it's currently close to 4x faster than the native Ruby URI parser
that comes with the [Ruby Standard Library](http://ruby-doc.org/stdlib-2.3.1/libdoc/uri/rdoc/URI.html).

There are a number of RFCs for URI syntax, but FastURI follows [rfc3986](https://tools.ietf.org/html/rfc3986).

It uses [Ragel](http://www.colm.net/open-source/ragel/) to generate a fast parser in C, which is then wrapped in the [Ruby C API](http://silverhammermba.github.io/emberb/c/).

## Usage

It's pretty simple to use, and there is currently only a single method
supported, FastURI#parse:

```ruby
FastURI.parse("http://foo@example.com:81/a/b/c?x=7&y=11#hola")

# which would return a plain-old ruby hash with the following fields
{
  userinfo: "foo",
  host: "example.com",
  port: 81,
  path: "/a/b/c",
  query: "x=7&y=11",
  fragment: "hola"
}

```

## Development

You'll need both [ragel](http://www.colm.net/open-source/ragel/) and [graphviz](http://www.graphviz.org/) installed, as well as a decent C compiler and a sane
development environment.

Run `bin/rake` to run ragel, the compiler, and to kick off the test suite.

If you have a bit of time (and you have graphviz installed), you can actually
generate a graph of the state machine that Ragel produces. It's pretty neat.

`bin/rake graph`

It will generate a file called "parser.png" in the doc/ directory.

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/jwhiteman/FastURI.

In particular, I could use help in two areas:

1. Adding more tests (I can guarantee there are some bugs to be found)
2. Adding some meaningful benchmarks compairing FastURI against Ruby's native [URI](https://docs.ruby-lang.org/en/2.1.0/URI.html).

## License

The gem is available as open source under the terms of the [MIT License](http://opensource.org/licenses/MIT).
