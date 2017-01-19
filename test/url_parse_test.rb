require 'test_helper'

# https://www.w3.org/Addressing/url_test/url.bnf
# http://www.cl.cam.ac.uk/~jac22/books/www/book/node166.html
class UrlParseTest < Minitest::Test
  def test_that_it_has_a_version_number
    refute_nil ::URLParse::VERSION
  end

  def test_initialize
    URLParse.new("helloZZ")
  end

  def test_parse
    URLParse.new("helloZZ").parse
  end
end
