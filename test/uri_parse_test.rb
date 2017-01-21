require "test_helper"

class URIParseTest < Minitest::Test
  def test_scheme
    results = URIParse.parse("http://fubar.com")

    assert results[:scheme] == "http"
  end
end
