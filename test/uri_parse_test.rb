require "test_helper"

def assert_parse(key, left, right)
  assert URIParse.parse(left)[key] == right
end

class URIParseTest < Minitest::Test
  def test_scheme
    assert_parse(:scheme, "http://foo.com", "http")
  end

  def test_hierpart_rootless
    assert_parse(:hier, "http:foo/bar", "foo/bar")
  end

  def test_hierpart_absolute
    assert_parse(:hier, "http:/foo/bar", "/foo/bar")
  end

  def test_ipv6
    assert_parse(:hier, "http://[A:A:A:A:A:A:B:B]", "//[A:A:A:A:A:A:B:B]")
    assert_parse(:hier, "http://[::A:A:A:A:A:B:B]", "//[::A:A:A:A:A:B:B]")
    assert_parse(:hier, "http://[A::A:A:A:A:B:B]", "//[A::A:A:A:A:B:B]")
    assert_parse(:hier, "http://[A:A::A:A:A:A:B]", "//[A:A::A:A:A:A:B]")
    assert_parse(:hier, "http://[A:A:A::A:A:A:A]", "//[A:A:A::A:A:A:A]")
    assert_parse(:hier, "http://[A:A:A:A::A:A:A]", "//[A:A:A:A::A:A:A]")
    assert_parse(:hier, "http://[A:A:A:A:A::A:A]", "//[A:A:A:A:A::A:A]")
    assert_parse(:hier, "http://[A:A:A:A:A:A::A]", "//[A:A:A:A:A:A::A]")
    assert_parse(:hier, "http://[A:A:A:A:A:A::]", "//[A:A:A:A:A:A::]")
  end

  def test_ipv4
    assert_parse(:hier, "http://192.168.1.1", "//192.168.1.1")
  end
end
