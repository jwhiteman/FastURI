require "spec_helper"

describe URLParse do
  describe "#parse" do
    it "parses relative netpaths" do
      up = URLParse.new("//foo-bar-baz")

      up.parse
    end

    it "parses relative netpaths with domain labels" do
      up = URLParse.new("//foo.bar.baz")

      up.parse
    end
  end
end

