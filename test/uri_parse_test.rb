require "test_helper"

def assert_parse(key, left, right)
  assert_equal URIParse.parse(left)[key], right
end

class URIParseTest < Minitest::Test
  def test_scheme
    assert_parse(:scheme, "http://foo.com", "http")
    assert_parse(:scheme, "https://foo.com", "https")
    assert_parse(:scheme, "ftp://foo.com", "ftp")
  end

  def test_hierpart_absolute
    assert_parse(:path, "http:/foo/bar", "/foo/bar")
    assert_parse(:path, "http://foo@example.com:81/a/b/c", "/a/b/c")
  end

  def test_relative
    assert_parse(:path, "/", "/")
    assert_parse(:path, "/foo/bar/baz", "/foo/bar/baz")
  end

  def test_ipv6
    assert_parse(:host, "http://[A:A:A:A:A:A:B:B]", "[A:A:A:A:A:A:B:B]")
    assert_parse(:host, "http://[::A:A:A:A:A:B:B]", "[::A:A:A:A:A:B:B]")
    assert_parse(:host, "http://[A::A:A:A:A:B:B]", "[A::A:A:A:A:B:B]")
    assert_parse(:host, "http://[A:A::A:A:A:A:B]", "[A:A::A:A:A:A:B]")
    assert_parse(:host, "http://[A:A:A::A:A:A:A]", "[A:A:A::A:A:A:A]")
    assert_parse(:host, "http://[A:A:A:A::A:A:A]", "[A:A:A:A::A:A:A]")
    assert_parse(:host, "http://[A:A:A:A:A::A:A]", "[A:A:A:A:A::A:A]")
    assert_parse(:host, "http://[A:A:A:A:A:A::A]", "[A:A:A:A:A:A::A]")
    assert_parse(:host, "http://[A:A:A:A:A:A::]", "[A:A:A:A:A:A::]")
  end

  def test_ipv4
    assert_parse(:host, "http://192.168.1.1", "192.168.1.1")
  end

  def test_userinfo
    assert_parse(:userinfo, "http://foo@example.com:81/a/b/c", "foo")
  end

  def test_query
    assert_parse(:query, "http://foo@example.com:81/a/b/c?x=7&y=11", "x=7&y=11")
  end

  def test_port
    assert_parse(:port, "http://192.168.1.1:3000", "3000")
  end

  def test_fragment
    assert_parse(:fragment, "http://foo@example.com:81/a/b/c?x=7&y=11#hola", "hola")
    assert_parse(:fragment, "/a/b/c?x=7&y=11+++++@@@@@@@@//////#hola", "hola")
  end
end
