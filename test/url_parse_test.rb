require 'test_helper'

class UrlParseTest < Minitest::Test
  def test_that_it_has_a_version_number
    refute_nil ::URLParse::VERSION
  end
end
